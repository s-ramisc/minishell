/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 22:46:41 by sramis-c          #+#    #+#             */
/*   Updated: 2022/03/06 22:49:29 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	char			x;

	i = 0;
	x = ((char)c);
	while (s[i] != '\0')
	{
		i++;
	}
	while (i > 0)
	{
		if (s[i] == x)
		{
			return (&((char *)s)[i]);
		}
		i--;
	}
	if (i == 0)
	{
		if (s[i] == x)
			return (&((char *)s)[i]);
	}
	return (0);
}
