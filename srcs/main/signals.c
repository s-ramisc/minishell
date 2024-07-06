/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:20:08 by sramis-c          #+#    #+#             */
/*   Updated: 2022/03/06 19:20:18 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	rl_replace_line(const char *str, int n);

void	signal_handler_child(int signum)
{
	if (signum == SIGQUIT)
	{
		g_exit_status = 131;
		ft_putstr_fd("Quit: 3\n", 1);
		signal(SIGQUIT, SIG_IGN);
	}
	if (signum == SIGINT)
	{
		g_exit_status = 130;
		printf("\n");
		signal(SIGINT, signal_handler);
	}
}

void	signal_handler(int signum)
{
	if (signum == SIGINT)
	{
		g_exit_status = 1;
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}
