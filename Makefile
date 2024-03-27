# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 15:48:46 by msaadidi          #+#    #+#              #
#    Updated: 2024/03/23 20:39:18 by msaadidi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = cc 
CFLAGS = -Os -Ofast -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
SRCS = FdF.c \
	gnl/get_next_line.c \
	fdf_utils/color_gradient.c \
	fdf_utils/color_utils.c \
	fdf_utils/drawing.c \
	fdf_utils/error_handling.c \
	fdf_utils/input_handling.c \
	fdf_utils/line_drawing.c \
	fdf_utils/map_geometry.c \
	fdf_utils/map_parser.c \
	fdf_utils/memory_management.c \
	fdf_utils/scaling_and_offsetting.c \
	fdf_utils/transformations.c
	
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a

all : $(NAME)

$(NAME) : $(OBJS)
	@cd libft && make && make clean
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(SRCS) $(LIBFT) -o $@
	@make clean

clean : 
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)

re : fclean all

.SECONDARY : $(OBJS)