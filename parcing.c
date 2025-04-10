/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:36:31 by sjoukni           #+#    #+#             */
/*   Updated: 2025/04/10 12:01:39 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int is_quote(char c)
{
    return (c == '\'' || c == '"');
}

int is_operator(char c)
{
    return (c == '|' || c == '<' || c == '>');
}

t_token *create_token(char *str, t_token_type type)
{
    t_token *new_token;

    new_token = malloc(sizeof(t_token));
    if (!new_token)
        return (NULL);
    new_token->value = strdup(str);
    new_token->type = type;
    new_token->next = NULL;
    return (new_token);
}


void append_token(t_token **head, t_token *new)
{
    t_token *temp;

    if (!*head)
    {
        *head = new;
        return;
    }
    temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = new;
}


int get_token_length(char *line, int i)
{
    int start = i;
    char quote_type;

    while (ft_isspace(line[i]))
        i++;
    if (is_quote(line[i]))
    {
        quote_type = line[i++];
        while (line[i] && line[i] != quote_type)
            i++;
        if (line[i] == quote_type)
            i++; 
        return i - start;
    }
    if (is_operator(line[i]))
    {
        if (is_operator(line[i + 1]) && line[i] == line[i + 1])
            return 2;
        return 1;
    }
    while (line[i] &&
           !ft_isspace(line[i]) &&
           !is_operator(line[i]) &&
           !is_quote(line[i]))
        i++;
    return i - start;
}

t_token_type get_token_type(char *str)
{
    if (!strcmp(str, "|"))
        return PIPE;
    if (!strcmp(str, ">"))
        return REDIR_OUT;
    if (!strcmp(str, ">>"))
        return APPEND;
    if (!strcmp(str, "<"))
        return REDIR_IN;
    if (!strcmp(str, "<<"))
        return HEREDOC;
    return WORD;
}

t_token *tokenize_line(char *line)
{
    int i = 0, len;
    t_token *head = NULL;
    char *token_str;
    t_token_type type;

    while (line[i])
    {
        while (ft_isspace(line[i]))
            i++;
        if (!line[i])
            break;
        len = get_token_length(line, i);
        token_str = strndup(line + i, len);
        type = get_token_type(token_str);

        append_token(&head, create_token(token_str, type));
        free(token_str);
        i += len;
    }
    return head;
}

