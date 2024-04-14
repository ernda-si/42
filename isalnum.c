/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:18:59 by ernda-si          #+#    #+#             */
/*   Updated: 2024/04/10 18:30:57 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isalnum(char av)
{
	return ((av >= 'a' && av <= 'z') || (av >= 'A' && av <= 'Z') || (av >= '0' && av <= '9'));
}

int	main(int ac, char **av)
{
	(void) ac;
	printf("%d\n", ft_isalnum(av[1][0]));
}

