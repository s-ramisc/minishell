/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:30:23 by omercade          #+#    #+#             */
/*   Updated: 2022/02/22 18:49:29 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ms_check_unset_arg(char *arg)
{
	int	i;

	i = 0;
	if (ft_isalpha(arg[i]) == 0 && arg[i] != '_')
	{
		printf("unset: '%s': not a valid identifier\n", arg);
		return (1);
	}
	i++;
	while (arg[i])
	{	
		if ((ft_isalnum(arg[i]) == 0 && arg[i] != '_') || arg[i] == '=')
		{
			printf("unset: '%s': not a valid identifier\n", arg);
			return (1);
		}
		i++;
	}
	return (0);
}

char	**ms_unset_remove(char **env, char *arg)
{
	char	*line;

	line = NULL;
	line = ms_get_env(env, arg);
	if (line != NULL)
		env = rm_strarr(env, line);
	return (env);
}

int	ft_unset(t_ms *data)
{
	int		i;
	char	**strings;
	char	**arg;
	int		ret;

	arg = ((t_token *)(data->tokenst->content))->args;
	ret = 0;
	i = 0;
	while (arg[i])
	{
		if (ms_check_unset_arg(arg[i]) != 0)
		{
			i++;
			ret = 1;
			continue ;
		}
		strings = ft_split(arg[i], '=');
		data->env = ms_unset_remove(data->env, strings[0]);
		free_strarr(strings);
		i++;
	}
	return (ret);
}
