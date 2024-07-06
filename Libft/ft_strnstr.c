/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 22:46:31 by sramis-c          #+#    #+#             */
/*   Updated: 2022/03/06 22:49:27 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *needle, size_t len)
{
	size_t	c;

	if (*needle == 0 || h == needle)
		return ((char *)h);
	c = ft_strlen(needle);
	while (*h && c <= len--)
	{
		if (!(ft_strncmp((char *)h, (char *)needle, c)))
			return ((char *)h);
		h++;
	}
	return (NULL);
}
