# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlevy <dlevy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/09 17:49:43 by dlevy             #+#    #+#              #
#    Updated: 2015/02/09 18:46:30 by dlevy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf
SRC		=	main.c create_map.c mod_line.c
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
