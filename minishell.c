/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:23:38 by sjoukni           #+#    #+#             */
/*   Updated: 2025/04/08 18:45:23 by sjoukni          ###   ########.fr       */
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

void print_list(t_list **head)
{
	t_list *tmp = *head;

	while (tmp)
	{
		printf("key: %s | value: %s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}


int main(int ac , char **av , char **envp)
{
    (void) ac;
    (void) av;
    
    int i = 0;
    t_list *env_list = NULL;

    while (envp[i])
    {
        t_list *node = ft_lstnew(envp[i]);
        if (node)
            append_env(&env_list, node);
        i++;
    }
    print_list(&env_list);
    


}