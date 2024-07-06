/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:58:06 by omercade          #+#    #+#             */
/*   Updated: 2022/03/06 22:36:54 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_all(t_ms data)
{
	free(data.env);
	free(data.secret);
	data.actual_token = NULL;
	ft_lstclear(&data.tokenst, free_token);
	return ;
}
