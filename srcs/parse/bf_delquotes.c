/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_delquotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:48:36 by omercade          #+#    #+#             */
/*   Updated: 2022/03/06 20:53:40 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

int	hasquotes(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			return (1);
		i++;
	}
	return (0);
}

int	quotes_len(char	*fragment, int *index)
{
	int		len;
	char	simbol;

	simbol = fragment[0];
	len = 1;
	while (fragment[len] != simbol)
		len++;
	*index += len;
	return (len - 1);
}

char	*add_str(char *origin, char *temp)
{
	char	*res;

	res = ft_strjoin(origin, temp);
	free(origin);
	free(temp);
	return (res);
}

char	*bf_delquotes(char *str)
{
	int		i;
	int		start;
	char	*res;

	if (!hasquotes(str))
		return (str);
	i = 0;
	start = 0;
	res = ft_strdup("");
	while (i < (int)ft_strlen(str))
	{
		if (str[i] == '\"' || str[i] == '\'')
		{
			res = add_str(res, ft_substr(str, start, i - start));
			start = i + 1;
			res = add_str(res, ft_substr(str, start, quotes_len(&str[i], &i)));
			start = ++i;
		}
		i++;
	}
	res = add_str(res, ft_substr(str, start, i - start));
	free(str);
	return (res);
}
