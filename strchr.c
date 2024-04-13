/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:51:43 by ernda-si          #+#    #+#             */
/*   Updated: 2024/04/10 12:34:32 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char    *ft_strchr(char *str, int c)
{
	int  i;

	i = 0;
	while (str[i] != c)
	{
		i++;
	}
	if (str[i] == c)
		return(&str[i]);
	return(0);
}

int main(void)
{
	printf("%s\n", ft_strchr("abacaxi", 'c'));
}