/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:50:42 by omercade          #+#    #+#             */
/*   Updated: 2022/02/28 17:51:23 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	display_array(char **arr, char *str)
{
	int	i;

	i = 0;
	if (!arr)
	{
		printf("NO ARGS!\n");
		return ;
	}
	while (arr[i] != 0)
	{
		printf("%s#%d: %s\t", str, i + 1, arr[i]);
		i++;
	}
	printf("\n");
	return ;
}
