/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 22:40:53 by sramis-c          #+#    #+#             */
/*   Updated: 2022/03/06 22:48:34 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*x;

	if (!lst)
		return ;
	while (*lst)
	{
		x = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		(*lst) = x;
	}
}
