/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpyUNF.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:14:18 by ernda-si          #+#    #+#             */
/*   Updated: 2024/04/14 17:24:48 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	
}

int	main(void)
{
	char	*dest = "///////";
	const char	*src = "abc";

	printf ("%s\n", ft_strlcpy(dest, src, 7));
	printf ("Original: %s\n", strlcpy(dest, src, 7));
}
