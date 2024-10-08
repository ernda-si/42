/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:12:06 by ernda-si          #+#    #+#             */
/*   Updated: 2024/10/04 14:56:10 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	*radix_sorting(int *lista)
{
	int	i;
	
	i = 0;

	return(lista);
}
struct staks *head = NULL;
struct node *current = NULL;

void PrintList()
{
	struct node *h = head;
	while (h != NULL)
	{
		printf("%d\n", h -> data);
		h = h -> next;
	}
}

int	main()
{
	int	lista[] = {1,2,3,4,5};
	int	*sorted_list = radix_sorting(lista);
	int	i = 0;

	while (i < 5)
		printf("%d\n", sorted_list[i++]);
}

//    Pb                 Pa           Pb         
//     00000001  >>  00000010 >>  00000100 >> 00001000
// a == 3,2,1,2,3 | a == 2,2   | a == 3,3 	| a == 
// b == /		  | b == 3,1,3 | b == 1,2,2	| b == 1,2,2,3,3

//
//			00000001		  00000010	  00000100	  00000001		00000010		00000100
// a == 1,2,3,4,5,4,3,2,1	| 2,4,4,2 	| 4,4,3,3 	| 3,3,5		  | 1,1			  | 1,1,2,2,3 | 1,1,2,2,3,4,4,5
// b ==						| 1,3,3,1,5 | 1,1,5,2,2	| 1,1,2,2,4,4 | 2,2,4,4,3,3,5 | 4,4,5	  | 

//			00000001		  00000010	  00000100	  00000001		00000010		00000100
// a == 5,4,3,2,1,2,3,4,5	| 4,2,2,4	| 1,4,4		  | 
// b ==						| 5,3,1,3,5	| 5,5,4,2,2,4 | 