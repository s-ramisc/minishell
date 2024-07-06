/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:57:35 by omercade          #+#    #+#             */
/*   Updated: 2022/03/06 20:12:01 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_redir(void *content)
{
	t_redirect	*temp;

	temp = (t_redirect *)content;
	free_strarr(temp->args);
	free(temp->simbol);
	if (temp)
		free(temp);
}
