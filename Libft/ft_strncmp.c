/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 22:46:22 by sramis-c          #+#    #+#             */
/*   Updated: 2022/03/06 22:49:25 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;
	size_t			c1;
	size_t			c2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	c1 = 0;
	c2 = 0;
	if (n == 0)
		return (c2);
	while ((ss1[c1] == ss2[c1] && ss1[c1] != '\0') && c1 < n)
		c1++;
	if (c1 == n)
		c1--;
	c2 = ss1[c1] - ss2[c1];
	return (c2);
}
