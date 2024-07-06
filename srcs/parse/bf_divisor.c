/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_divisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:01:20 by omercade          #+#    #+#             */
/*   Updated: 2022/03/07 01:48:10 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

static void	temp_arg(char *line, t_list **argst, char **env, int len)
{
	char	*aux;

	aux = ft_substr(line, 0, len);
	if (ft_strlen(aux) > 0)
		bf_div_addarg(aux, argst, env);
	else
		free(aux);
}

void	bf_divisor(char *line, t_token *token, t_list **argst, char **env)
{
	int		i;
	int		start;
	int		*quotes;

	quotes = bf_escapes(line);
	start = 0;
	i = 0;
	while ((size_t)i < ft_strlen(line))
	{
		if ((line[i] == ' ' || line[i] == '<'
				|| line[i] == '>') && quotes[i] == 0)
		{
			temp_arg(&line[start], argst, env, i - start);
			if (line[i] == '<')
				i += bf_div_addredir(&line[i], &token->in, env);
			else if (line[i] == '>')
				i += bf_div_addredir(&line[i], &token->out, env);
			start = i + 1;
		}
		i++;
	}
	temp_arg(&line[start], argst, env, i - start);
	free(quotes);
	return ;
}
