/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_openprocess.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:29:46 by omercade          #+#    #+#             */
/*   Updated: 2022/03/06 23:37:17 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	in_redirect(t_ms *data)
{
	int		fd;
	t_token	*actual_t;

	actual_t = ((t_token *)(data->actual_token->content));
	fd = exe_redirect(actual_t->in, STDIN_FILENO);
	if (fd == -1)
		exit(-1);
	else if (fd > 2)
	{
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
}

static void	out_redirect(t_ms *data)
{
	int		fd;
	t_token	*actual_t;
	t_token	*next_t;

	actual_t = (t_token *)(data->actual_token->content);
	next_t = (t_token *)(data->actual_token->next->content);
	fd = actual_t->fd_out;
	if (fd > 2)
	{
		close(next_t->fd[1]);
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	else
	{
		dup2(next_t->fd[1], STDOUT_FILENO);
		close(next_t->fd[1]);
	}
}

void	exe_openprocess(t_ms *data)
{
	t_token	*actual_t;
	t_token	*next_t;

	actual_t = (t_token *)(data->actual_token->content);
	next_t = (t_token *)(data->actual_token->next->content);
	pipe(next_t->fd);
	actual_t->pid = fork();
	if (actual_t->pid == 0)
	{
		actual_t->fd_out = exe_redirect(actual_t->out, STDOUT_FILENO);
		close(next_t->fd[0]);
		in_redirect(data);
		out_redirect(data);
		if (actual_t->fd_out != -2 && exe_builtin(data) == -1)
		{
			if (actual_t->args)
				exe_process(actual_t, data->env);
		}
		exit(0);
	}
	else
	{
		data->actual_token = data->actual_token->next;
		exe_multiprocess(data);
	}
}
