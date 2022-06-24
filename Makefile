# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mouarsas <mouarsas@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 18:19:31 by mouarsas          #+#    #+#              #
#    Updated: 2022/06/17 23:45:22 by mouarsas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = so_long_bonus

SRC = window.c \
	  so_long.c \
	  play.c \
	  check_map.c \
	  get_next_line/get_next_line_utils.c \
	  get_next_line/get_next_line.c \
	  ft_printf/ft_hexa.c \
	  ft_printf/ft_pointer.c \
	  ft_printf/ft_printf.c \
	  ft_printf/ft_putchar.c \
	  ft_printf/ft_putnbr_unsigned.c \
	  ft_printf/ft_putnbr.c \
	  ft_printf/ft_putstr.c \

SRC_BONUS = bonus/window_bonus.c \
	  		bonus/so_long_bonus.c \
	  		bonus/play_bonus.c \
	  		bonus/check_map_bonus.c \
	  		bonus/get_next_line/get_next_line_utils.c \
	  		bonus/get_next_line/get_next_line.c \
	  		bonus/ft_printf/ft_pointer.c \
			bonus/ft_printf/ft_hexa.c \
	  		bonus/ft_printf/ft_printf.c \
	  		bonus/ft_printf/ft_putchar.c \
	  		bonus/ft_printf/ft_putnbr_unsigned.c \
	  		bonus/ft_printf/ft_putnbr.c \
	  		bonus/ft_printf/ft_putstr.c \

OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(MLX) $(OBJ) -o $(NAME)
%.o:%.c so_long.h bonus/so_long_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@
bonus: $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(MLX) -o $(NAME)
clean :
		@rm -rf $(OBJ) $(OBJ_BONUS)
fclean : clean
		@rm -rf $(NAME) $(NAME_BONUS)

re : fclean all bonus
