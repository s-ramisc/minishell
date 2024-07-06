/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 22:40:27 by sramis-c          #+#    #+#             */
/*   Updated: 2022/03/06 22:48:27 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*i;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	i = *lst;
	while (i->next)
	{
		i = i->next;
	}
	i->next = new;
}
