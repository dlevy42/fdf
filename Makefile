# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlevy <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/24 13:01:50 by dlevy             #+#    #+#              #
#    Updated: 2015/02/05 15:04:30 by dlevy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf
SRC		=	main.c create_map.c draw_line.c print_map.c
OBJ		=	$(SRC:.c=.o)
HDR		=	libft/includes/
MLX		=	-L/usr/X11/lib -lmlx -lXext -lX11
FLAGS	=	-Wall -Wextra -Werror
CC		=	gcc

%.o: %.c
		@$(CC) $(FLAGS) -I . -I /usr/X11/include/ -o $@ -c $?

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/ fclean && make -C libft/ && $(CC) $(FLAGS) $(MLX) -o $(NAME)\
		$(OBJ) libft/libft.a -I /usr/X11/include/

clean:
	@rm -f $(OBJ)

cleanlib:
	@make -C libft/ fclean

fclean: clean cleanlib
	@rm -f $(NAME)

re: fclean all
