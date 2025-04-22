/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:06:52 by sjoukni           #+#    #+#             */
/*   Updated: 2025/04/22 17:05:34 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void free_array(char **arr)
{
    int i = 0;
    while (arr[i])
        free(arr[i++]);
    free(arr);
}
void free_cmd(t_cmd *cmd)
{
    if (!cmd)
        return;
    if (cmd->args)
        free_array(cmd->args);
    if (cmd->infile)
        free(cmd->infile);
    if (cmd->outfile)
        free(cmd->outfile);
    if (cmd->heredoc_delim)
        free(cmd->heredoc_delim);
    free(cmd);
}
void free_cmd_list(t_cmd *cmd_list)
{
    t_cmd *tmp;

    while (cmd_list)
    {
        tmp = cmd_list->next;
        free_cmd(cmd_list);
        cmd_list = tmp;
    }
}
