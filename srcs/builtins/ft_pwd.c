/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:30:43 by omercade          #+#    #+#             */
/*   Updated: 2022/02/22 18:49:22 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_pwd(t_ms *data)
{
	char	c[PATH_MAX];
	int		fd;

	fd = ((t_token *)(data->actual_token->content))->fd_out;
	if (getcwd(c, sizeof(c)) == NULL)
		return (1);
	ft_putstr_fd(c, fd);
	ft_putstr_fd("\n", fd);
	return (0);
}
