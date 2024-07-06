/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_expansions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:41:07 by omercade          #+#    #+#             */
/*   Updated: 2022/03/07 02:43:21 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

int	iseov(char c)
{
	if (c == 0)
		return (1);
	else if (c == '$')
		return (1);
	else if (c == ' ')
		return (1);
	else if (c == '?')
		return (1);
	else if (c == 34)
		return (1);
	else if (c == 39)
		return (1);
	else if (c < 48)
		return (0);
	else if (c >= 65 && c <= 90)
		return (0);
	else if (c >= 97 && c <= 122)
		return (0);
	else if (c == '_')
		return (0);
	return (1);
}

char	*exp_variable(char *expand, char **env)
{
	int		i;
	char	*mod;
	char	*temp;

	if (!ft_strcmp("?\0", expand))
	{
		free(expand);
		return (ft_itoa(g_exit_status));
	}
	mod = ft_strdup("");
	temp = ft_strjoin(expand, "=");
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(temp, env[i], ft_strlen(temp)) == 0)
		{
			free(mod);
			mod = ft_substr(env[i], ft_strlen(temp),
					ft_strlen(env[i]) - ft_strlen(temp));
		}
		i++;
	}
	free(expand);
	free(temp);
	return (mod);
}

char	*exp_contructor(char *str, int start, int len, char **env)
{
	char	*aux;
	char	*end;
	char	*res;

	res = ft_substr(str, 0, start);
	end = exp_variable(ft_substr(str, start + 1, len - 1), env);
	aux = ft_strjoin(res, end);
	free(res);
	free(end);
	end = ft_substr(str, start + len, ft_strlen(str) - len);
	res = ft_strjoin(aux, end);
	free(aux);
	free(end);
	free(str);
	return (res);
}

int	exp_length(char *str)
{
	int	len;

	len = 1;
	while (str[len])
	{
		if (str[len] == '?')
			return (len + 1);
		else if (iseov(str[len]))
			return (len);
		len++;
	}
	return (len);
}

char	*bf_expansions(char *str, char **env)
{
	int		*quotes;
	int		i;
	int		start;
	int		len;
	char	*res;

	quotes = bf_escapes(str);
	i = -1;
	start = -1;
	len = 0;
	while (str[++i])
	{
		if (str[i] == '$' && quotes[i] < 2)
		{
			start = i;
			len = exp_length(&str[i]);
			break ;
		}
	}
	free(quotes);
	if (start == -1)
		return (str);
	res = exp_contructor(str, start, len, env);
	res = bf_expansions(res, env);
	return (res);
}
