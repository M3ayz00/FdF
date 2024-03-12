# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaadidi <msaadidi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 15:48:46 by msaadidi          #+#    #+#              #
#    Updated: 2024/03/12 17:09:31 by msaadidi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = cc 
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
SRCS = FdF.c bersenham_algo.c projection.c get_map.c color.c gradient.c getters.c draw.c scale_n_offset.c gnl/get_next_line.c error.c free.c
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