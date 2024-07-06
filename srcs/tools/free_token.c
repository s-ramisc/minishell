/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:57:22 by omercade          #+#    #+#             */
/*   Updated: 2022/03/06 21:25:41 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_token(void *content)
{
	t_token	*temp;

	temp = (t_token *)content;
	free_strarr(temp->args);
	if (temp->in)
		ft_lstclear(&temp->in, free_redir);
	if (temp->out)
		ft_lstclear(&temp->out, free_redir);
	if (temp)
		free(temp);
}
