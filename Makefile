# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 17:22:08 by aalfahal          #+#    #+#              #
#    Updated: 2023/02/03 21:44:45 by aalfahal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

NAME1	=	so_long

SRC1	=	src/map_parsing.c	\
			src/map_components.c\
			src/drawing_map.c	\
			src/drawing_map2.c	\
			src/so_long.c		\
			src/dir_draw.c		\
			src/valid_path.c

SRCS1	=	$(SRC1:%.c=%.o)

all : $(NAME1)

$(NAME1) : $(SRCS1)
	@make all -C ./ft_printf
	@make all -C ./libft
	@make all -C ./get_next_line
	$(CC) $(CFLAGS) $(SRCS1) -framework OpenGL -framework AppKit -o $(NAME1) libft/libft.a get_next_line/gnl.a ft_printf/libftprintf.a mlx/libmlx.a 
clean:
	rm -fr $(SRCS1) ./libft/*.o ./get_next_line/*.o ./ft_printf/*.o mlx/*.o

fclean: clean
	rm -fr $(NAME1) libft/libft.a get_next_line/gnl.a ft_printf/libftprintf.a 

re: fclean all