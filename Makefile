# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 15:48:46 by msaadidi          #+#    #+#              #
#    Updated: 2024/03/18 21:12:32 by msaadidi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = cc 
CFLAGS = -Os -Ofast -Wall -Wextra -Werror 
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
SRCS = gnl/get_next_line.c \
	color_gradient.c \
	color_utils.c \
	drawing.c \
	error_handling.c \
	FdF.c \
	input_handling.c \
	line_drawing.c \
	map_geometry.c \
	map_parser.c \
	memory_management.c \
	scaling_and_offsetting.c \
	transformations.c
	
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a

all : $(NAME)

$(NAME) : $(OBJS)
	cd libft && make && make clean
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(SRCS) $(LIBFT) -o $@
	make clean

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re : fclean all

.SECONDARY : $(OBJS)