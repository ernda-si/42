# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kali <kali@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/27 16:58:06 by ernda-si          #+#    #+#              #
#    Updated: 2024/12/12 19:00:54 by kali             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = push_swap.c push_swap_utils.c pushes.c rotates.c im_tired.c \
rrotates.c swaps.c ft_split.c minions.c helper_functions.c utils.c \
parsing.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	 $(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all