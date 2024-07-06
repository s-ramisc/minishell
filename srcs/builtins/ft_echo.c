/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:28:37 by omercade          #+#    #+#             */
/*   Updated: 2022/02/22 18:48:48 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	n_args(char **args)
{
	int	len;

	len = 0;
	while (args[len])
		len++;
	return (len);
}

int	n_flag(char **args)
{
	int	ret;
	int	i;
	int	j;

	i = 1;
	ret = 0;
	while (ft_strncmp(args[i], "-n", 2) == 0)
	{
		j = 1;
		while (args[i][j])
		{
			if (args[i][j] != 'n')
				return (ret);
			j++;
		}
		ret++;
		i++;
	}
	return (ret);
}

int	ft_echo(t_ms *data)
{
	int		i;
	int		n_opt;
	int		fd;
	char	**args;

	args = ((t_token *)(data->actual_token->content))->args;
	fd = ((t_token *)(data->actual_token->content))->fd_out;
	i = 1;
	n_opt = 0;
	if (n_args(args) > 1)
	{
		n_opt = n_flag(args);
		i += n_opt;
		while (args[i])
		{
			ft_putstr_fd(args[i], fd);
			if (args[i + 1] && args[i][0] != '\0')
				write(fd, " ", 1);
			i++;
		}
	}
	if (n_opt == 0)
		write(fd, "\n", 1);
	return (0);
}
