# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/31 16:24:54 by ernda-si          #+#    #+#              #
#    Updated: 2025/04/10 16:15:28 by ernda-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	pipex.c ft_substr.c ft_split.c \
		ft_strlen.c ft_strjoin.c ft_strnstr.c \
		ft_strdup.c comands_exec.c aux_functions.c \

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

NAME = pipex

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -g -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all