/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:56:19 by hakader           #+#    #+#             */
/*   Updated: 2025/04/24 16:00:21 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_token
{
	char			*value;
	int				type;
	struct s_token	*next;
}	t_token;

typedef enum e_token_type
{
    WORD,
    PIPE,
    REDIR_OUT,
    REDIR_IN,
    APPEND,
    HEREDOC,
    SEMICOLON
} t_token_type;


typedef struct s_cmd
{
	char				**args;
	char			*infile;
	char			*outfile;
	int				append;
	int				has_pipe;
	char			*heredoc_delim;
	int  			heredoc_expand;
	struct s_cmd	*next;
}	t_cmd;

# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "libft/libft.h"
# include "parsing/parsing.h"
# include "execution/execution.h"
# include <signal.h>

# define RESET		"\x1b[0m"
# define BLACK		"\x1b[30m"
# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define WHITE		"\x1b[37m"

#endif
