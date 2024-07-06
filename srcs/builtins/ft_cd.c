/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:29:46 by omercade          #+#    #+#             */
/*   Updated: 2022/02/22 18:48:26 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ms_get_env(char **env, char *arg)
{
	int		i;
	char	**split;

	i = 0;
	while (env[i])
	{
		split = ft_split(env[i], '=');
		if (ft_strcmp(split[0], arg) == 0)
		{
			free_strarr(split);
			break ;
		}
		else
			i++;
		free_strarr(split);
	}
	if (env[i] == NULL)
		return (NULL);
	return (env[i]);
}

char	**set_pwd(char *arg, char *path, char **env)
{
	char	*string;

	string = ft_strjoin(arg, path);
	env = rm_strarr(env, arg);
	env = add_strarr(env, string);
	free (string);
	return (env);
}

char	*go_home(char **env)
{
	char	*path;

	path = ms_get_env(env, "HOME") + 5;
	if ((path - 5) == NULL)
	{
		printf("cd: HOME not set\n");
		return (NULL);
	}
	return (path);
}

int	ft_cd(t_ms *data)
{
	char	c[PATH_MAX];
	char	**arg;
	char	*path;

	arg = ((t_token *)(data->tokenst->content))->args;
	path = arg[1];
	if (arg[1] == NULL)
		path = go_home(data->env);
	getcwd(c, sizeof(c));
	if (chdir(path) != 0)
	{
		if (path == NULL)
			return (1);
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putendl_fd(": No such file or directory", 2);
		return (1);
	}
	data->env = set_pwd("OLDPWD=", c, data->env);
	getcwd(c, sizeof(c));
	data->env = set_pwd("PWD=", c, data->env);
	return (0);
}
