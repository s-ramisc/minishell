/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 22:42:56 by sramis-c          #+#    #+#             */
/*   Updated: 2022/03/06 22:48:56 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*x;
	const unsigned char	*y;

	x = ((unsigned char *)dst);
	y = ((const unsigned char *)src);
	if (x == y)
		return (dst);
	else if (x > y)
	{
		y = y + len - 1;
		x = x + len - 1;
		while (len > 0)
		{
			*x = *y;
			x--;
			y--;
			len--;
		}
	}
	else
		dst = ft_memcpy(x, y, len);
	return (dst);
}
