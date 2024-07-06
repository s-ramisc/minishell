/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 22:41:46 by sramis-c          #+#    #+#             */
/*   Updated: 2022/03/06 22:48:41 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *l, void *(*f)(void *), void (*del)(void *))
{
	t_list	*x;
	t_list	*new;

	if (!l)
		return (NULL);
	new = ft_lstnew(f(l->content));
	if (!(new))
		return (NULL);
	x = new;
	while (l)
	{
		if (l->next)
		{
			new->next = ft_lstnew(f(l->next->content));
			if (!(new->next))
			{
				ft_lstclear(&new, del);
				return (NULL);
			}
			new = new->next;
		}
		l = l->next;
	}
	new->next = NULL;
	return (x);
}
