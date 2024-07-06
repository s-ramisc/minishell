/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:10:21 by omercade          #+#    #+#             */
/*   Updated: 2022/03/06 23:11:03 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

int	word_count(char *s)
{
	int		comp;
	int		cles;
	int		i;
	int		*quotes;

	quotes = bf_escapes(s);
	comp = 0;
	cles = 0;
	if (*s == '\0')
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ' && quotes[i] == 0)
			cles = 0;
		else if (cles == 0)
		{
			cles = 1;
			comp++;
		}
		i++;
	}
	free(quotes);
	return (comp);
}
