/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:39:45 by ernda-si          #+#    #+#             */
/*   Updated: 2024/04/17 20:07:12 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	int		i;
	int		i2;
	char	*s3;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	i2 = 0;
	s3 = (char *) malloc (sizeof(char) * (len1 + len2 + 1));
	while (i < len1)
	{
		s3[i] = s1[i];
		i++;
	}
	while (i2 < len2)
	{
		s3[i] = s2[i2];
		i++;
		i2++;
	}
	s3[i] = '\0';
	return (s3);
}

int	main(void)
{
	char	*ts;
	char	*ts2;

	ts = "te";
	ts2 = "a";
	printf("str1: %s\n", ts);
	printf("str2: %s\n", ts2);
	printf("strjoin: %s\n", ft_strjoin(ts, ts2));
}
