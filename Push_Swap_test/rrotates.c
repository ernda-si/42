/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotates.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:55:41 by ernda-si          #+#    #+#             */
/*   Updated: 2024/09/27 17:26:16 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	rrotate_a(struct Stacks **head)
{
	struct Stacks	*end;
	struct Stacks	*last;

	if (!*head || !(*head)-> next)
		exit(0);
	end = *head;
	while (end -> next -> next)
		end = end -> next;
	last = end -> next;
	end -> next = NULL;
	last -> next = *head;
	*head = last;
	write(1, "rra\n", 4);
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	rrotate_b(struct Stacks **head_b)
{
	struct Stacks	*end;
	struct Stacks	*last;

	if (!*head_b || !(*head_b)-> next)
		exit(0);
	end = *head_b;
	while (end -> next -> next)
		end = end -> next;
	last = end -> next;
	end -> next = NULL;
	last -> next = *head_b;
	*head_b = last;
	write(1, "rrb\n", 4);
}

// rrr : rra and rrb at the same time.
void	rrotate_ab(struct Stacks **head, struct Stacks **head_b)
{
	struct Stacks	*end;
	struct Stacks	*last;

	if (!*head || !*head_b || !(*head)-> next || !(*head_b)-> next)
		exit(0);
	end = *head;
	while (end -> next -> next)
		end = end -> next;
	last = end -> next;
	end -> next = NULL;
	last -> next = *head;
	*head = last;
	end = *head_b;
	while (end -> next -> next)
		end = end -> next;
	last = end -> next;
	end -> next = NULL;
	last -> next = *head_b;
	*head_b = last;
	write(1, "rrr\n", 4);
}