/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:43:21 by ernda-si          #+#    #+#             */
/*   Updated: 2024/10/30 13:14:41 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_num(struct Stacks *head)
{
	struct Stacks	*big_num;
	struct Stacks	*temp;
	int				max;

	big_num = head;
	temp = create_node(head->number);
	temp->next = head->next;
	while (big_num)
	{
		if ((temp -> number) < (big_num -> number) && big_num)
			temp -> number = big_num -> number;
		big_num = big_num -> next;
	}
	max = temp->number;
	free(temp);
	// printf("max_number: %d\n", max)
	return (max);
}

int	find_min_num(struct Stacks *head)
{
	struct Stacks	*small_num;
	struct Stacks	*temp;
	int				min;

	small_num = head;
	temp = create_node(head->number);
	temp->next = head->next;
	while (small_num)
	{
		if ((temp -> number) > (small_num -> number) && small_num)
			temp -> number = small_num -> number;
		small_num = small_num -> next;
	}
	min = temp->number;
	free(temp);
	// printf("min_number: %d\n", min);
	return (min);
}

int	lst_size(struct Stacks *head)
{
	int	size;

	size = 0;
	while (head)
	{
		head = head -> next;
		size++;
	}
	// printf("size: %d\n", size);
	return (size);
}

void	min_max(struct Stacks **head, struct Stacks **head_b)
{
	int	max_num;
	int	min_num;

	max_num = find_max_num(*head);
	min_num = find_min_num(*head);
	while ((*head))
	{
		rotate_a(head);
		if ((*head)-> number == max_num)
		{
			push_b(head_b, head);
			break ;
		}
	}
	while ((*head))
	{
		rotate_a(head);
		if ((*head)-> number == min_num)
		{
			push_b(head_b, head);
			break ;
		}
	}
}

void	small_sort(struct Stacks **head)
{
	if ((*head)-> number > (*head)-> next -> number)
		swap_a(*head);
	else
		return ;
}

void	medium_sort(struct Stacks **head)
{
	int	first;
	int	second;
	int	third;
	
	first = (*head)-> number;
	second = (*head)-> next -> number;
	third = (*head)-> next -> next -> number;
	// 1 < 2  < 3 null
	if (first < second && second < third)
		return ;
	// 1 < 3 > 2 sa ra
	else if (first < second && second > third && third > first)
		return (swap_a(*head), rotate_a(head));
	// 2 > 1 < 3 sa
	else if(first > second && second < third && third > first)
		return (swap_a(*head));
	// 2 < 3 > 1 rra
	else if(first < second && second > third && third < first)
		return (rrotate_a(head));
	// 3 > 2 > 1 rra rra
	else if(first > second && second > third)
		return (rotate_a(head), swap_a(*head));
	// 3 > 1 < 2 ra
	else if(first > second && second < third)
		return (rotate_a(head));
}

int	last_node(struct Stacks *head)
{
	int	size;
	struct Stacks *temp;

	size = lst_size(head);
	temp = head;
	while (--size)
		temp = temp -> next;
	return (temp -> number);
}

int	better_moves(struct Stacks *head, struct Stacks *head_b)
{
	int	size;
	int	mid;
	int	counter;
	struct Stacks *temp;

	size = lst_size(head);
	mid = size / 2;
	counter = 0;
	temp = head;
	while (temp -> number > head_b -> number && last_node(temp) < head_b -> number)
	{
		temp = temp -> next;
		counter++;
		printf("count ");
	}
	if (counter < mid && counter < size)
		return (counter);
	else if (counter > mid && counter < size)
		return (counter);
	return(0);
}

void	big_sort(struct Stacks **head, struct Stacks **head_b)
{
	int	last;
	printf("min number: %d\n", find_min_num(*head));
	// while ((*head)-> number != find_min_num(*head))
	// 	rotate_a(head);
	push_b(head_b, head);
	push_b(head_b, head);
	small_sort(head_b);
	medium_sort(head);
	while (*head_b)
	{ // 1 3 5 4 2 > 1 3 | 2 4 5 > 
		last = last_node(*head);
		if ((*head_b)-> number > last && (*head_b)-> number < (*head)-> number)
		{
			rotate_a(head);
			push_a(head, head_b);
		}
		else if ((*head_b)-> number < last && (*head_b)-> number > (*head)-> number)
			rotate_a(head);
		else
			rotate_a(head);
	}
	return ;
}

void	rmedium_sort(struct Stacks **head)
{
	int	first;
	int	second;
	int	third;
	
	first = (*head)-> number;
	second = (*head)-> next -> number;
	third = (*head)-> next -> next -> number;
	// 1 < 2  < 3 null
	if (first > second && second > third)
		return ;
	// 1 < 3 > 2 sa ra
	else if (first > second && second < third && third < first)
		return (swap_a(*head), rotate_a(head));
	// 2 > 1 < 3 sa
	else if(first < second && second > third && third < first)
		return (swap_a(*head));
	// 2 < 3 > 1 rra
	else if(first > second && second < third && third > first)
		return (rrotate_a(head));
	// 3 > 2 > 1 rra rra
	else if(first < second && second < third)
		return (rotate_a(head), swap_a(*head));
	// 3 > 1 < 2 ra
	else if(first < second && second > third)
		return (rotate_a(head));
}

// 1 3 2 5 4 6 8 9 7
void	sort(struct Stacks **head, struct Stacks **head_b)
{
	int	mid;
	int	i = 0;

	mid = lst_size(*head) / 2;
	while (lst_size(*head_b) != 3)
	{
		if ((*head)-> number == find_min_num(*head) || (*head)-> number == find_max_num(*head))
			rotate_a(head);
		push_b(head_b, head);
	}
	rmedium_sort(head_b);
	while (head_b && head)
	{
		if ((*head)-> number > (*head_b)-> number 
			&& (*head)-> number < last_node(*head_b))
			push_b(head_b, head);
		else if (better_moves(*head, *head_b) > mid)
			rrotate_b(head_b);
		else if (better_moves(*head, *head_b) <= mid)
			rotate_b(head_b);
		i++;
		if (i == 15 || (*head)-> number < last_node(*head_b)
			&& (*head_b)-> number == find_max_num(*head_b))
		{
			push_b(head_b, head);
			break;
		}
	}
	rotate_b(head_b);
	while ((*head_b))
		push_a(head, head_b);
} // 1 3 2 7 4 6 5 // 

int	has_num(struct Stacks *head, int num)
{
	struct Stacks	*check;

	check = head;
	while (check)
	{
		if (check -> number == num)
			return (1);
		check = check -> next;
	}
	return (0);
}

void	free_lst(struct Stacks **head, struct Stacks **head_b)
{
	struct Stacks	*temp;
	int				size;
	int				size_b;

	size = lst_size(*head);
	size_b = lst_size(*head_b);
	if ((*head))
	{
		while (--size)
		{
			temp = (*head);
			while (temp)
				temp = temp -> next;
			free(temp);
		}
	}
	if ((*head_b))
	{
		while (--size_b)
		{
			temp = (*head_b);
			while (temp)
				temp = temp -> next;
			free(temp);
		}
	}
}

void sort_handler(struct Stacks **head, struct Stacks **head_b)
{
	int	size;

	size = lst_size(*head);
	if (size == 1)
		return ;
	else if (size == 2)
		return (small_sort(head));
	else if (size == 3)
		return (medium_sort(head));
	else if (size == 5)
		return (big_sort(head, head_b));
	else if (size > 5)
		return (sort(head, head_b));
	return ;
}

int	ft_strlen(const char *str)
{
	if (!*str)
		return 0;
	return ft_strlen((str + 1)) + 1;
}

void	push_swap(int ac, char *arr[])
{
	struct Stacks	*head;
	struct Stacks	*head_b;
	int				arg;
	int				num;

	arg = 0;
	while (++arg < ac)
	{
		if (!str_checker (arr[arg]))
		{
			free_lst(&head, &head_b);
			exit(1);
		}
		num = ft_atoi (arr[arg]);
		if ((head && has_num(head, num)))
		{
			write(2, "Error\n", 6);
			free_lst(&head, &head_b);
			exit(1);
		}
		head = lstadd (num, head);
	}
	head_b = (struct Stacks *) malloc (sizeof(struct Stacks));
	if (!head_b)
		return ;
	head_b = NULL;

	printf("Stack A before sorting:\n");
	print_list(head);
	printf("Stack B before sorting:\n");
	print_list(head_b);

	sort_handler(&head, &head_b);

	printf("Stack A after sorting:\n");
	print_list(head);
	printf("Stack B after sorting:\n");
	print_list(head_b);

	free_lst(&head, &head_b);
	return ;
}

int	main(int ac, char *av[])
{
	push_swap(ac, av);
	return (1);
}
