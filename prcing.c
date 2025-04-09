/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prcing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:36:31 by sjoukni           #+#    #+#             */
/*   Updated: 2025/04/09 13:59:51 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int calcule_len(char *line)
{
    int i = 0;

    while (line[i] && ft_isspace(line[i]))
        i++;

    if (line[i] == '\'' || line[i] == '\"')
    {
        char quote = line[i]; 
        i++;
        while (line[i] && line[i] != quote) 
            i++;
        if (line[i] == quote)
            i++;
    }
    else if (line[i] == '>' || line[i] == '<' || line[i] == '|')
    {
        if (line[i + 1] == line[i]) 
            i += 2; 
        else
            i++;  
    }
    else
    {
        while (line[i] && !ft_isspace(line[i]) && line[i] != '\'' && line[i] != '\"' && 
               line[i] != '>' && line[i] != '<' && line[i] != '|')
        {
            i++; 
        }
    }

    return i;
}


char *value(char * line)
{
    int i = 0;
    char *value;
    int len;

    len = calcule_len(char *line);
    value = malloc()
    if (ft_isspace(line[i]))
    {
        i++;
    }
    while (line[i])
    {
        i++;
    }
    
    
}



t_token *ft_lstnew(char *content)
{
    t_token *new_node = malloc(sizeof(t_token));
    if (!new_node)
        return NULL;
        
    new_node->value = value(content);
    new_node->type = type(content);
    new_node->next = NULL;

    return new_node;
}


t_token tokenize_line(char *line)
{
    
}

char *parce_line(char *line)
{
	tokenize_line(char *line);
}