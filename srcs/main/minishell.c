/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:23:32 by omercade          #+#    #+#             */
/*   Updated: 2022/03/06 22:36:18 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <signal.h>

char	**get_env(char **env)
{
	int		i;
	char	**myenv;

	i = 0;
	while (env[i] != NULL)
		i++;
	myenv = malloc((i + 1) * sizeof(char *));
	i = 0;
	while (env[i] != NULL)
	{
		myenv[i] = ft_strdup(env[i]);
		i++;
	}
	myenv[i] = NULL;
	return (myenv);
}

t_ms	initializer(char **xarg, char **env)
{
	t_ms	this;

	(void)xarg;
	this.exit = 0;
	this.env = get_env(env);
	header();
	return (this);
}

int	main(int narg, char **xarg, char **env)
{
	t_ms	this;
	char	*buf;

	if (narg != 1)
		return (!printf("ARGS ERROR!!\n"));
	this = initializer(xarg, env);
	while (this.exit == 0)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, signal_handler);
		buf = readline(BLUE "minishell:/>" WHITE" ");
		if (!buf)
			exit(!printf("exit\n"));
		if (buf && *buf != '\0')
		{
			add_history(buf);
			this.tokenst = babelfish(ft_strjoin(buf, "\0"), this.env);
			execalibur(&this);
			ft_lstclear(&this.tokenst, free_token);
		}
		free(buf);
	}
	free(this.env);
	free_all(this);
	return (0);
}
