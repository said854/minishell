/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:20:48 by sjoukni           #+#    #+#             */
/*   Updated: 2025/04/09 16:35:44 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H


typedef struct s_token
{
	char *value;
	int type; 
	struct s_token *next;
} t_token;

typedef enum e_token_type
{
    WORD,       // 0: words
    PIPE,       // 1: |
    REDIR_IN,   // 2: <
    REDIR_OUT,  // 3: >
    APPEND,     // 4: >>
    HEREDOC     // 5: <<
} t_token_type;

# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
#include "libft/libft.h"


char *parce_line(char *line);
t_token *tokenize_line(char *line);



#endif