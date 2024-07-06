/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:24:08 by omercade          #+#    #+#             */
/*   Updated: 2021/12/15 17:38:31 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	header(void)
{
	printf(RED "           _       _      _          _ _ \n");
	printf("          (_)     (_)    | |        | | |\n");
	printf(" _ __ ___  _ _ __  _  ___| |__   ___| | |\n");
	printf("| '_ ` _ \\| | '_ \\| |/ __| '_ \\ / _ \\ | |\n");
	printf("| | | | | | | | | | |\\__ \\ | | |  __/ | |\n");
	printf("|_| |_| |_|_|_| |_|_||___/_| |_|\\___|_|_|");
	printf(YELLOW "\tHello %s\n\n" NC, getenv("USER"));
	return ;
}

// void    ft_prompt(void)
// {
//     printf("\n\n");
//     printf(YELLOW "     &\n");
//     printf(" .-\"`\"-.\n");
//     printf("/       \\\n");
//     printf("|   __  _|\n");
//     printf("|  /  \\`/ \\\n");
//     printf("WW  \\_o/_o/\n");
//     printf("(        _)\n");
//     printf("|   .----\\\n");
//     printf(";  | '----'"); printf(YELLOW "\tHello %s\n" NC, getenv("USER"));
//     printf("\\__'--;`\n");
//     printf("|___/\\|\n" NC);
//     printf("\n\n\n");
// }
