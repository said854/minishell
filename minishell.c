/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:23:38 by sjoukni           #+#    #+#             */
/*   Updated: 2025/04/12 18:00:47 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void append_env(t_list **head, t_list *new_node)
{
	if (!*head)
	{
		*head = new_node;
		return;
	}
	t_list *tmp = *head;
	while (tmp->next)
		tmp = tmp->next;

	tmp->next = new_node; 
}

void print_list(t_token *head)
{
	t_token *tmp = head;

	while (tmp)
	{
		printf("value: %s || type: %d\n", tmp->value, tmp->type);
		tmp = tmp->next;
	}
}

int is_empty(char *line)
{
	if (line[0] == '\0')
	{
		return (1);
	}
	return 0;
}
void print_list_env(t_list **head)
{
    t_list *tmp = *head;

    while (tmp)
    {
        printf("key: %s | value: %s\n", tmp->key, tmp->value);
        tmp = tmp->next;
    }
}
#include <stdio.h>

void print_cmd_list(t_cmd *cmd_list)
{
    int i;
    int cmd_num = 1;

    while (cmd_list)
    {
        printf("🔹 CMD %d:\n", cmd_num++);

        // Print args
        printf("  args    = ");
        if (cmd_list->args)
        {
            i = 0;
            while (cmd_list->args[i])
                printf("\"%s\" ", cmd_list->args[i++]);
        }
        else
            printf("(none)");
        printf("\n");

        // Print redirections
        printf("  infile  = %s\n", cmd_list->infile ? cmd_list->infile : "(none)");
        printf("  outfile = %s\n", cmd_list->outfile ? cmd_list->outfile : "(none)");
        printf("  append  = %d\n", cmd_list->append);
        printf("  pipe    = %s\n", cmd_list->has_pipe ? "true" : "false");
        printf("\n");

        cmd_list = cmd_list->next;
    }
}

int main(int ac, char **av, char **envp)
{
    (void) ac;
    (void) av;
    char *line;
    int i = 0;
    t_list *env_list = NULL;
    t_token *cmd;
    t_cmd *f_cmd;
    while (envp[i])
    {
        t_list *node = ft_lstnew(envp[i]);
        if (node)
            append_env(&env_list, node);
        i++;
    }
    // print_list_env(&env_list);
    // print_list(&env_list);
    while (1)
    {
        line = readline("minishell$ ");
        if (!line)
        {
            free(line);
            exit(1);
        }
        if (is_empty(line))
        {
            free(line);
            continue;
        }
        add_history(line);

        int last = 0;
        cmd = tokenize_line(line, env_list, last);
        if (check_syntax(cmd))
        {
            f_cmd = build_cmd_list(cmd);
            print_cmd_list(f_cmd);
        }
        // free_token_list(cmd); 
        // free(line);
    }
    return (0);
}
