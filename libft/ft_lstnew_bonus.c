/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:08:35 by sjoukni           #+#    #+#             */
/*   Updated: 2025/04/08 16:15:43 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *key(char *str)
{
    int i = 0;
    while (str[i] && str[i] != '=')
        i++;

    char *key = malloc(i + 1);
    if (!key)
        return NULL;

    int j = 0;
    while (j < i)
    {
        key[j] = str[j];
        j++;
    }
    key[i] = '\0';

    return key;
}

char *value(char *str)
{
    int i = 0;
    while (str[i] && str[i] != '=')
        i++;

    if (str[i] == '\0') 
        return NULL;

    i++; 
    int len = 0;
    while (str[i + len])
        len++;

    char *value = malloc(len + 1);
    if (!value)
        return NULL;

    int j = 0;
    while (j < len)
    {
        value[j] = str[i + j];
        j++;
    }
    value[len] = '\0';

    return value;
}

t_list *ft_lstnew(char *content)
{
    t_list *new_node = malloc(sizeof(t_list));
    if (!new_node)
        return NULL;

    new_node->key = key(content);
    new_node->value = value(content);
    new_node->next = NULL;

    return new_node;
}
