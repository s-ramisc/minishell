/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:29:59 by omercade          #+#    #+#             */
/*   Updated: 2022/02/22 18:48:55 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_env(t_ms *data)
{
	int	i;
	int	fd;

	i = 0;
	fd = ((t_token *)(data->actual_token->content))->fd_out;
	while (data->env[i])
	{
		if (ft_strchr(data->env[i], '=') != NULL)
		{
			ft_putstr_fd(data->env[i], fd);
			write(fd, "\n", 1);
		}
		i++;
	}
	return (0);
}
