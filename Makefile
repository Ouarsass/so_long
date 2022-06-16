# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mouarsas <mouarsas@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 18:19:31 by mouarsas          #+#    #+#              #
#    Updated: 2022/06/14 01:55:42 by mouarsas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = window.c \
	  so_long.c \
	  play.c \
	  check_map.c \
	  get_next_line/get_next_line_utils.c \
	  get_next_line/get_next_line.c \
	  ft_printf/hexa.c \
	  ft_printf/ft_pointer.c \
	  ft_printf/ft_printf.c \
	  ft_printf/ft_putchar.c \
	  ft_printf/ft_putnbr_umsigned.c \
	  ft_printf/ft_putnbr.c \
	  ft_printf/ft_putstr.c \

OBJ = ${SRC:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(MLX) $(OBJ) ft_printf/libftprintf.a -o $(NAME)

%.o:%.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@




clean :
		@rm -rf $(OBJ)

fclean : clean
		@rm -rf $(NAME)

re : fclean all bonus
