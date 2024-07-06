/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_escapes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:41:39 by omercade          #+#    #+#             */
/*   Updated: 2022/03/07 03:30:59 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

int	el_simple(int *set)
{
	if (*set == 2)
	{
		*set = 0;
		return (2);
	}
	else if (*set == 1)
		return (*set);
	else
	{
		*set = 2;
		return (2);
	}
}

int	el_double(int *set)
{
	if (*set == 2)
		return (*set);
	else
	{
		*set = !(*set);
		return (1);
	}
}

int	escape_level(int *this, char *str, int i, int set)
{
	if (str[i] == '\'')
		this[i] = el_simple(&set);
	else if (str[i] == '\"')
		this[i] = el_double(&set);
	else
		this[i] = set;
	return (set);
}

int	*bf_escapes(char *str)
{
	int	*quotes;
	int	i;
	int	set;

	quotes = malloc(sizeof(int) * ft_strlen(str));
	if (!quotes)
		return (NULL);
	set = 0;
	i = 0;
	while (str[i])
	{
		set = escape_level(quotes, str, i, set);
		i++;
	}
	if (set != 0)
	{
		free(quotes);
		return (NULL);
	}
	return (quotes);
}
