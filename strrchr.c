/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:02:25 by ernda-si          #+#    #+#             */
/*   Updated: 2024/04/08 19:09:33 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char    *ft_strrchr(char *str, int c)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    while (str[i] != c)
        i--;
    return(&str[i]);
}

int main(void)
{
    printf("%s\n", ft_strrchr("abacaxi", 'a'));
}