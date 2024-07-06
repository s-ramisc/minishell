/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 22:34:49 by omercade          #+#    #+#             */
/*   Updated: 2022/03/06 17:21:15 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	menu_option(char *cmd)
{	
	if (!ft_strcmp("cd\0", cmd))
		return (0);
	if (!ft_strcmp("echo\0", cmd))
		return (1);
	if (!ft_strcmp("env\0", cmd))
		return (2);
	if (!ft_strcmp("export\0", cmd))
		return (3);
	if (!ft_strcmp("pwd\0", cmd))
		return (4);
	if (!ft_strcmp("unset\0", cmd))
		return (5);
	if (!ft_strcmp("exit\0", cmd))
		return (6);
	return (-1);
}

static void	*menu_builtin(void)
{
	int	(**menu)(t_ms *);

	menu = malloc(sizeof(*menu) * 8);
	menu[0] = &ft_cd;
	menu[1] = &ft_echo;
	menu[2] = &ft_env;
	menu[3] = &ft_export;
	menu[4] = &ft_pwd;
	menu[5] = &ft_unset;
	menu[6] = &ft_exit;
	menu[7] = (void *)0;
	return (menu);
}

int	exe_builtin(t_ms *data)
{
	int	(**menu)(t_ms *);
	int	opt;

	menu = menu_builtin();
	opt = menu_option(((t_token *)(data->actual_token->content))->args[0]);
	if (opt >= 0)
		g_exit_status = menu[opt](data);
	free(menu);
	return (opt);
}
