/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:23:38 by sjoukni           #+#    #+#             */
/*   Updated: 2025/04/10 12:13:50 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"

// void append_env(t_list **head, t_list *new_node)
// {
// 	if (!*head)
// 	{
// 		*head = new_node;
// 		return;
// 	}
// 	t_list *tmp = *head;
// 	while (tmp->next)
// 		tmp = tmp->next;

// 	tmp->next = new_node; 
// }

// void print_list(t_token *head)
// {
// 	t_token *tmp = head;

// 	while (tmp)
// 	{
// 		printf("value: %s || type: %d\n", tmp->value, tmp->type);
// 		tmp = tmp->next;
// 	}
// }

// int is_empty(char *line)
// {
// 	if (line[0] == '\0')
// 	{
// 		return (1);
// 	}
// 	return 0;
// }




// int main(int ac, char **av, char **envp)
// {
//     (void) ac;
//     (void) av;
//     char *line;
//     int i = 0;
//     t_list *env_list = NULL;
//     t_token *cmd;

//     while (envp[i])
//     {
//         t_list *node = ft_lstnew(envp[i]);
//         if (node)
//             append_env(&env_list, node);
//         i++;
//     }

//     while (1)
//     {
//         line = readline("minishell$ ");
//         if (!line)
//         {
//             free(line);
//             exit(1);
//         }
//         if (is_empty(line))
//         {
//             free(line);
//             continue;
//         }
//         add_history(line);

//         cmd = tokenize_line(line);
//         print_list(cmd);

		
//         // free_token_list(cmd); 
//         // free(line);
//     }
//     return (0);
// }
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