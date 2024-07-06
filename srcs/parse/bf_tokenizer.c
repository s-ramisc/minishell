/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:31:59 by omercade          #+#    #+#             */
/*   Updated: 2022/03/06 21:30:03 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

char	**lsttoargs(t_list **argst)
{
	t_list	*aux;
	char	**args;
	int		len;
	int		i;

	len = ft_lstsize(*argst);
	if (len < 1)
		return (NULL);
	args = malloc(sizeof(char *) * (len + 1));
	if (!args)
		return (NULL);
	i = 0;
	aux = *argst;
	while (aux)
	{
		args[i++] = ft_strdup((char *)(aux->content));
		aux = aux->next;
	}
	args[i] = 0;
	return (args);
}

t_list	*bf_tokenizer(char *buf, char **env)
{
	t_token	*new;
	t_list	*argst;

	if (ft_strlen(buf) <= 0)
	{
		free (buf);
		return (NULL);
	}
	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->in = NULL;
	new->out = NULL;
	argst = NULL;
	bf_divisor(buf, new, &argst, env);
	if (argst != NULL)
	{
		new->args = lsttoargs(&argst);
		ft_lstclear(&argst, free);
	}
	else
		new->args = NULL;
	free (buf);
	return (ft_lstnew(new));
}
