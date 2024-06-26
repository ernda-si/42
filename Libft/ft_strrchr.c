/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:02:25 by ernda-si          #+#    #+#             */
/*   Updated: 2024/05/10 13:43:41 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != (unsigned char)c && i != 0)
		i--;
	if (i == 0 && str[i] != (unsigned char)c)
		return (NULL);
	return (&str[i]);
}
// 5 8 issues //
/* int	main(void)
{
	printf("%s\n", ft_strrchr("abacaxi", ' '));
	printf("%s\n", strrchr("abacaxi", ' '));
} */
