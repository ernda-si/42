/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:43:21 by ernda-si          #+#    #+#             */
/*   Updated: 2024/11/25 16:36:00 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_n(struct Stacks *head)
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
	return (max);
}

int	min_n(struct Stacks *head)
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
	return (size);
}

void	min_max(struct Stacks **head, struct Stacks **head_b)
{
	int	max_num;
	int	min_num;

	max_num = max_n(*head);
	min_num = min_n(*head);
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

void	rsmall_sort(struct Stacks **head)
{
	if ((*head)-> number < (*head)-> next -> number)
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

// f_b < f_a && f_b > l_a
int	bst_moves(struct Stacks *head, struct Stacks *head_b)
{
	int	counter;
	struct Stacks *start;

	counter = 0;
	start = head;
	while (start -> number < head_b -> number || last_node(start) > head_b -> number)
	{
		start = start -> next;
		counter++;
		if (!start)
			break;
	}
	return(counter);
}

void	big_sort(struct Stacks **head, struct Stacks **head_b)
{
	int	last;
	printf("min number: %d\n", min_n(*head));
	// while ((*head)-> number != min_n(*head))
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

int	find_max(struct Stacks **head)
{
	struct Stacks *temp;
	int	max;
	int	i;

	i = 0;
	temp = *head;
	max = max_n(*head);
	while (temp -> number != max && temp)
	{
		i++;
		temp = temp -> next;
	}
	return (i);
}

int find_min(struct Stacks **head)
{
	struct Stacks *temp;
	int	min;
	int	i;

	i = 0;
	temp = *head;
	min = min_n(*head);
	while (temp -> number != min && temp)
	{
		i++;
		temp = temp -> next;
	}
	return (i);
}

int	has_bigger(struct Stacks **head, struct Stacks **head_b)
{
	struct Stacks *temp;
	
	temp = *head;
	while (temp -> number < (*head_b)-> number)
	{
		temp = temp -> next;
		if (temp -> next == NULL)
			return (0);
	}
	return (1);
}

int	has_smaller(struct Stacks **head, struct Stacks **head_b)
{
	struct Stacks *temp;
	
	temp = *head;
	while (temp -> number > (*head_b)-> number)
	{
		temp = temp -> next;
		if (temp -> next == NULL)
			return (0);
	}
	return (1);
}
// 1 3 2 -2 7 6 4 -1 // -2 7 6 4 -1 | 2 3 1
// max_num na head // (rotate _a if max_num_A < mid) ou (rrotate_A if max_num_A > mid)
// min_num na head // (rotate _a if min_num_A < mid) ou (rrotate_A if min_num_A > mid)

// (push_a swap_a if min ou max da head_b for == min ou max da head)

// general cases better moveset // (rotate_a if bst_moves <= mid) ou 
// (rrotate_a if bst_moves >= mid)
void handler(struct Stacks **head, struct Stacks **head_b)
{
	int	moves;
	int	mid;

	mid = lst_size(*head) / 2;
	moves = bst_moves(*head, *head_b);
 	if (max_n(*head) == (*head)-> number && max_n(*head_b) == (*head_b)-> number)
	{
		push_a(head, head_b);
		swap_a(*head);
	}
	else if (min_n(*head) == (*head)-> number && min_n(*head_b) == (*head_b)-> number)
		push_a(head, head_b);
	else if (max_n(*head) == (*head)-> number && !has_bigger(head, head_b))
		push_a(head, head_b);
	else if (min_n(*head) == (*head)-> number && !has_smaller(head, head_b))
		push_a(head, head_b);
	else if (moves <= mid)
		return(rotate_a(head));
	else if (moves > mid)
		return(rrotate_a(head));
}

void end_sort(struct Stacks **head)
{
	while (find_min(head) > lst_size(*head) / 2)
		rrotate_a(head);
	while (find_min(head) < lst_size(*head) / 2 && min_n(*head) != (*head)-> number)
		rotate_a(head);
	if (last_node(*head) != max_n(*head))
		return (rrotate_a(head), swap_a(*head));
}

// 2 6 4 -1 1 3 | 7 -2 // 6 4 -1 1 3 | 2 7 -2 // 4 -1 1 3 | 6 7 -2 2 // -1 1 3 | 4 6 7 -2 2 //
// 1 3 | 2 4 6 7 -2 -1 // 3 | 1 2 4 6 7 -2 -1 // 1 2 3 4 6 7 -2 -1 // -1 1 2 3 4 6 7 -2 //
// -2 -1 1 2 3 4 6 7
// if (fA > fB && fA > lB) (rotate_b if < mid && existir) ou (rrotate_b if > mid && < size)
// if (fA < fB && fA < lB) (rotate_b if < mid && existir) ou (rrotate_b if > mid && < size)
// if (fA < fB && fA > lB) push_b
// if (fA > fB && fA < lB) (rotate_b if < mid && existir) ou (rrotate_b if > mid && < size)

void	sort(struct Stacks **head, struct Stacks **head_b)
{
	int	f_b;
	int	f_a;
	int	l_a;
	int	i = 0;

	while ((lst_size(*head)) > 3)
		push_b(head_b, head);
	medium_sort(head);
	while (head_b && (*head_b))
	{
		f_b = (*head_b)-> number;
		f_a = (*head)-> number;
		l_a = last_node(*head);
		if (f_b < f_a && f_b > l_a)
			push_a(head, head_b);
		else if ((f_b < f_a && f_b < l_a) || (f_b > f_a && f_b > l_a) || (f_b > f_a && f_b < l_a))
			handler(head, head_b);
		i++;
		if (i == 1)
			break;
	}
	end_sort(head);
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

void	free_lst(struct Stacks **head)
{
	struct Stacks	*temp;
	int				size;

	size = lst_size(*head);
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
	char			**matrix;
	int				arg;
	int				num;

	if (ac > 2)
		exit(0);
	arg = 0;
	matrix = ft_split(arr[1], ' ');
	printf("matrix: %s\n", *matrix);
	while (matrix[arg])
	{
		if (!str_checker (matrix[arg]))
		{
			free_lst(&head);
			exit(1);
		}
		num = ft_atoi (matrix[arg]);
		if ((head && has_num(head, num)))
		{
			write(2, "Error\n", 6);
			free_lst(&head);
			exit(1);
		}
		head = lstadd (num, head);
		arg++;
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

	free_lst(&head);
	return ;
}

int	main(int ac, char *av[])
{
	(void) ac;
	if (ac < 2)
		return(0);
	push_swap(ac, av);
	return (1);
}
