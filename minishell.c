/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:23:38 by sjoukni           #+#    #+#             */
/*   Updated: 2025/04/17 15:53:02 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int is_empty(char *line)
{
	if (line[0] == '\0')
	{
		return (1);
	}
	return 0;
}
int main(int ac, char **av, char **envp)
{
    (void) ac;
    (void) av;
    char *line;
    int i = 0;
    t_env *env_list = NULL;
    t_token *cmd;
    t_cmd *f_cmd;
    while (envp[i])
    {
        t_env *node = env_copy(envp[i]);
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
            // parce_cmd(f_cmd);
            print_cmd_list(f_cmd);
        }
        // free_token_list(cmd); 
        // free(line);
    }
    return (0);
}
