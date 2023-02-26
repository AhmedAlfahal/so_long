# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 17:22:08 by aalfahal          #+#    #+#              #
#    Updated: 2023/02/26 18:00:12 by aalfahal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

NAME1	=	so_long

SRC1	=	src/map_parsing.c	\
			src/map_components.c\
			src/drawing_map.c	\
			src/so_long.c		\
			src/valid_path.c

SRCS1	=	$(SRC1:%.c=%.o)

all : $(NAME1)

$(NAME1) : $(SRCS1)
	@make all -C ./ft_printf
	@make all -C ./libft
	@make all -C ./get_next_line
	$(CC) $(CFLAGS) $(SRCS1) -framework OpenGL -framework AppKit -o $(NAME1) libft/libft.a get_next_line/gnl.a ft_printf/libftprintf.a mlx/libmlx.a 
clean:
	rm -fr $(SRCS1)
	@make clean -C ./ft_printf
	@make clean -C ./libft
	@make clean -C ./get_next_line

fclean: clean
	rm -fr $(NAME1)
	@make fclean -C ./ft_printf
	@make fclean -C ./libft
	@make fclean -C ./get_next_line

re: fclean all