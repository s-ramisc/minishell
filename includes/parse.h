/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 04:51:42 by sramis-c          #+#    #+#             */
/*   Updated: 2022/03/07 04:51:45 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

/*
** INCLUDES
*/
# include "../Libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
/*
** MACROS
*/
# define EMPTY 0
# define EXEC 1
# define BUILTIN 2
# define ARG 3
# define PIPE 4
# define REDIR 5
# define TRUNC 6
# define EXIT 9

/*
** ERROR TAGS
*/
# define UNERR "Unknown error..."

/*
** STRUCTS & ENUMS
*/

int	g_exit_status;
typedef enum e_redir_type
{
	redir_out,
	redir_out_append,
	redir_in,
	here_doc,
	none
}			t_redir_type;

typedef struct s_token
{
	char			**args;
	t_list			*in;
	t_list			*out;
	pid_t			pid;
	int				fd[2];
	int				fd_out;
	int				status;
}					t_token;

typedef struct s_redirect
{
	char			**args;	
	char			*simbol;
}					t_redirect;

/*
** FUNCTIONS
*/
t_list	*babelfish(char *buf, char **env);
t_list	*bf_tokenizer(char *buf, char **env);
int		*bf_escapes(char *str);
char	*bf_expansions(char *str, char **env);
char	*bf_delquotes(char *str);
void	bf_divisor(char *line, t_token *token, t_list **argst, char **env);
void	bf_div_addarg(char *line, t_list **flst, char **env);
int		bf_div_addredir(char *line, t_list **lst, char **env);

int		word_count(char *s);
void	display_array(char **arr, char *str);
void	display_lst(t_list *lst, char *str);
void	display_tokens(t_list *token);

#endif
