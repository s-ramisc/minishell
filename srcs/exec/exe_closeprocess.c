/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_closeprocess.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:30:19 by omercade          #+#    #+#             */
/*   Updated: 2022/03/07 04:26:06 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	wait_for_all(t_ms *data)
{
	t_token	*actual_t;

	data->actual_token = data->tokenst;
	while (data->actual_token)
	{
		actual_t = (t_token *)(data->actual_token->content);
		waitpid(actual_t->pid, &actual_t->status, 0);
		if (actual_t->status == 2)
			g_exit_status = 130;
		if (actual_t->status == 3)
			g_exit_status = 131;
		data->actual_token = data->actual_token->next;
	}
	actual_t = (t_token *)(ft_lstlast(data->tokenst)->content);
	if (WIFEXITED(actual_t->status))
	{
		if (WEXITSTATUS(actual_t->status) == 255)
			g_exit_status = 127;
		else
			g_exit_status = WEXITSTATUS(actual_t->status);
	}
}

static void	close_fd(t_ms *data)
{
	t_token	*actual_t;

	actual_t = (t_token *)(data->actual_token->content);
	close(actual_t->fd[1]);
	close(actual_t->fd[0]);
}

static void	in_redirect(t_ms *data)
{
	int		fd;
	t_token	*actual_t;

	actual_t = (t_token *)(data->actual_token->content);
	fd = exe_redirect(actual_t->in, STDIN_FILENO);
	if (fd == -1)
		exit(-1);
	else if (fd > 2)
	{
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

	actual_t = (t_token *)(data->actual_token->content);
	fd = actual_t->fd_out;
	if (fd == -1)
		exit(-1);
	else if (fd > 2)
	{
		close(actual_t->fd[1]);
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	else
		close(actual_t->fd[1]);
}

void	exe_closeprocess(t_ms *data)
{
	t_token	*actual_t;

	actual_t = (t_token *)(data->actual_token->content);
	actual_t->pid = fork();
	if (actual_t->pid == 0)
	{
		actual_t->fd_out = exe_redirect(actual_t->out, STDOUT_FILENO);
		if (actual_t->fd_out != -2 && exe_builtin(data) == -1)
		{
			in_redirect(data);
			out_redirect(data);
			if (actual_t->args)
				exe_process(actual_t, data->env);
		}
		exit(0);
	}
	else
		close_fd(data);
	wait_for_all(data);
}
