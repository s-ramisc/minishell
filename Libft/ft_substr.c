/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 22:47:00 by sramis-c          #+#    #+#             */
/*   Updated: 2022/03/06 22:49:32 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*x;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (*s == '\0')
		return (ft_strdup(""));
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	x = (char *)malloc(sizeof(char) * len + 1);
	if (!(x))
		return (NULL);
	while (i < len)
	{
		x[i] = s[start + i];
		i++;
	}
	x[i] = '\0';
	return (x);
}
