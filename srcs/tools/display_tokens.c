/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:50:10 by omercade          #+#    #+#             */
/*   Updated: 2022/02/28 17:52:13 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	display_tokens(t_list *token)
{
	t_list	*aux;
	int		i;

	aux = token;
	i = 1;
	while (aux)
	{
		printf("TOKEN #%d\n", i);
		display_array(((t_token *)(aux->content))->args, "ARG");
		display_lst(((t_token *)(aux->content))->in, "IN");
		display_lst(((t_token *)(aux->content))->out, "OUT");
		printf("\n");
		aux = aux->next;
		i++;
	}
	return ;
}
