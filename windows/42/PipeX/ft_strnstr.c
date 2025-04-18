/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:02:48 by ernda-si          #+#    #+#             */
/*   Updated: 2025/04/10 16:05:18 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr(char const *str1, char const *str2, int len)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	if (str2[0] == '\0')
		return ((char *)str1);
	if (len < 0)
		len = ft_strlen(str1);
	while (str1[i] != '\0' && i < len)
	{
		while ((str1[i] == str2[i2] || str2[i2] == '\0') && i <= len)
		{
			if (str2[i2] == '\0')
				return ((char *)&str1[i - i2]);
			i2++;
			i++;
		}
		i -= i2;
		i++;
		i2 = 0;
	}
	return (NULL);
}
