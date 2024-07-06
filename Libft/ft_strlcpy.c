/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 22:45:49 by sramis-c          #+#    #+#             */
/*   Updated: 2022/03/06 22:49:18 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		len;
	size_t		c1;
	size_t		c2;

	c1 = 0;
	if (!src)
		return (0);
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	c2 = dstsize - 1;
	while (c2 > 0 && src[c1] != '\0')
	{
		dst[c1] = src[c1];
		c1++;
		c2--;
	}
	dst[c1] = '\0';
	return (len);
}
