/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:15:20 by ernda-si          #+#    #+#             */
/*   Updated: 2024/05/10 14:03:41 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char const *str1, char const *str2, int n)
{
	int	i;

	i = 0;
	if (n < 0)
		n = ft_strlen(str1) + ft_strlen(str2);
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && i < (n - 1) && str1[i] && str2[i])
	{
		i++;
		if (str1[i] > 126 || str2[i] > 126 || str2[i] == '\0')
			return (1);
	}
	return (str1[i] - str2[i]);
}

/* int	main(int ac, char **av)
{
	(void) ac;
	
	printf("My: %d\n", ft_strncmp(av[1], av[2], 6));
	printf("Original: %d\n", strncmp(av[1], av[2], 6));
} */
