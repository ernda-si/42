/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:23:35 by kali              #+#    #+#             */
/*   Updated: 2024/12/09 17:11:22 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct Stacks
{
	int				number;
	int				index;
	int				flag;
	struct Stacks	*next;
}	t_Stacks;

	// struct Stacks	*head = NULL;
	// struct Stacks	*head_b = NULL;

struct Stacks	*lstadd(int new_data, struct Stacks *start);
struct Stacks	*create_node(int new_data);
void			print_list(struct Stacks *head);
void			push_a(struct Stacks **head, struct Stacks **head_b);
void			push_b(struct Stacks **head_b, struct Stacks **head);
void			rotate_a(struct Stacks **head);
void			rotate_b(struct Stacks **head_b);
void			rotate_ab(struct Stacks **head, struct Stacks **head_b);
void			rrotate_a(struct Stacks **head);
void			rrotate_b(struct Stacks **head_b);
void			rrotate_ab(struct Stacks **head, struct Stacks **head_b);
void			swap_a(struct Stacks *head);
void			swap_b(struct Stacks *head_b);
void			swap_swap(struct Stacks *head, struct Stacks *head_b);
void			index_num(struct Stacks **head);
void			free_lst(struct Stacks *head, char **matrix);
void			sort_handler(struct Stacks **head, struct Stacks **head_b);
void			printf_bin(unsigned int num);
char			**ft_split(char const *s, char c);
int				str_checker(char *str);
int				ft_atoi(char const *str);
int				has_num(struct Stacks *head, int num);
int				lst_size(struct Stacks *head);
int				min_n(struct Stacks *head);
int				max_n(struct Stacks *head);
int				ft_strlen(const char *str);
int				bin_count(int num);
int				bin_left(struct Stacks *head, int exp);
struct Stacks	*last_node(struct Stacks *head);
void			push_swap(int ac, char *arr[]);
void			small_sort(struct Stacks **head);
void			medium_sort(struct Stacks **head);
void			sort(struct Stacks **head, struct Stacks **head_b);

#endif