/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_div_addarg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:18:29 by omercade          #+#    #+#             */
/*   Updated: 2022/03/07 01:28:59 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

static void	add_arg(char *line, t_list **flst)
{
	if (ft_strlen(line) < 1)
		return ;
	line = bf_delquotes(line);
	ft_lstadd_back(flst, ft_lstnew((void *)line));
}

void	bf_div_addarg(char *line, t_list **flst, char **env)
{
	int	*quotes;
	int	start;
	int	i;

	if (ft_strlen(line) < 1)
		return ;
	line = bf_expansions(line, env);
	quotes = bf_escapes(line);
	start = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' && quotes[i] == 0)
		{
			add_arg(ft_substr(line, start, i - start), flst);
			start = i + 1;
		}
		i++;
	}
	add_arg(ft_substr(line, start, i - start), flst);
	free(line);
	free(quotes);
	return ;
}
