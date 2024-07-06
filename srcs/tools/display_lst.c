/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:50:30 by omercade          #+#    #+#             */
/*   Updated: 2022/02/28 17:51:54 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	display_lst(t_list *lst, char *str)
{
	int	i;

	i = 0;
	if (!lst)
	{
		printf("NO %s_LST!\n", str);
		return ;
	}
	while (lst)
	{
		printf("%s_LST #%d->\t", str, i);
		printf("(%s)", ((t_redirect *)(lst->content))->simbol);
		display_array(((t_redirect *)(lst->content))->args, "LST_ARG");
		lst = lst->next;
		i++;
	}
	return ;
}
