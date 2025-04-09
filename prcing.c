/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prcing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:36:31 by sjoukni           #+#    #+#             */
/*   Updated: 2025/04/09 13:43:24 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *value(char * line)
{
    int i = 0;

    
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