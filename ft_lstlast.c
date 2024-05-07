/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:55:14 by ernda-si          #+#    #+#             */
/*   Updated: 2024/05/07 14:59:41 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
	while (lst + 1 != NULL)
	{
		lst = lst -> next;
	}
	return(lst);
}

int	main(void)
{
	printf("last node of the list: %d\n", ft_lstlast());
}