/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_multiprocess.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:29:59 by omercade          #+#    #+#             */
/*   Updated: 2022/03/07 04:25:52 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	close_fd(t_ms *data)
{
	t_token	*actual_t;
	t_token	*next_t;

	actual_t = (t_token *)(data->actual_token->content);
	next_t = (t_token *)(data->actual_token->next->content);
	close(actual_t->fd[0]);
	close(actual_t->fd[1]);
}

static void	in_redirect(t_ms *data)
{
	int		fd;
	t_token	*actual_t;
	t_token	*next_t;

	actual_t = (t_token *)(data->actual_token->content);
	next_t = (t_token *)(data->actual_token->next->content);
	fd = exe_redirect(actual_t->in, STDIN_FILENO);
	if (fd == -1)
		exit(-1);
	else if (fd > 0)
	{
		close(actual_t->fd[0]);
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	else
	{
		dup2(actual_t->fd[0], STDIN_FILENO);
		close(actual_t->fd[0]);
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
	if (fd == -1)
		exit(-1);
	else if (fd > 2)
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

static void	exe_mp_offspring(t_ms *data)
{
	t_token	*actual_t;
	t_token	*next_t;

	actual_t = (t_token *)(data->actual_token->content);
	next_t = (t_token *)(data->actual_token->next->content);
	actual_t->fd_out = exe_redirect(actual_t->out, STDOUT_FILENO);
	close(next_t->fd[0]);
	close(actual_t->fd[1]);
	if (actual_t->fd_out != -2 && exe_builtin(data) == -1)
	{
		in_redirect(data);
		out_redirect(data);
		if (actual_t->args)
			exe_process(actual_t, data->env);
	}
	exit(0);
}

void	exe_multiprocess(t_ms *data)
{
	t_token	*actual_t;
	t_token	*next_t;

	if (data->actual_token->next)
	{
		actual_t = (t_token *)(data->actual_token->content);
		next_t = (t_token *)(data->actual_token->next->content);
		pipe(next_t->fd);
		actual_t->pid = fork();
		if (actual_t->pid == 0)
			exe_mp_offspring(data);
		else
		{
			close_fd(data);
			data->actual_token = data->actual_token->next;
			exe_multiprocess(data);
		}
	}
	else
		exe_closeprocess(data);
}
