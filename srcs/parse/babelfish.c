/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   babelfish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:40:51 by omercade          #+#    #+#             */
/*   Updated: 2022/03/07 03:30:54 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

static t_list	*token_divider(char *buf, char **env, int *quotes, t_list *tk)
{
	int		start;
	int		i;

	start = 0;
	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '|' && quotes[i] == 0)
		{
			ft_lstadd_back(&tk,
				bf_tokenizer(ft_substr(buf, start, i - start), env));
			start = i + 1;
		}
		i++;
	}
	ft_lstadd_back(&tk,
		bf_tokenizer(ft_substr(buf, start, i - start), env));
	free(buf);
	return (tk);
}

t_list	*babelfish(char *buf, char **env)
{
	int		*quotes;
	t_list	*first_t;

	quotes = bf_escapes(buf);
	if (!quotes)
	{
		free(buf);
		ft_putstr_fd("minishell: unclosed quotes\n", 2);
		g_exit_status = 42;
		return (NULL);
	}
	first_t = token_divider(buf, env, quotes, NULL);
	free(quotes);
	return (first_t);
}
