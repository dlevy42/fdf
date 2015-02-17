# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/13 19:04:09 by bfrimin           #+#    #+#              #
#    Updated: 2015/02/16 17:18:49 by bfrimin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	=	fdf
SRC		=	main.c \
			stock.c
OBJ		=	$(SRC:.c=.o)
HDR		=	libft/includes/
MLX		=	-L/usr/X11/lib -lmlx -lXext -lX11
FLAGS	=	-Wall -Wextra -Werror
CC		=	gcc

%.o: %.c
		@$(CC) -I ./includes -I /usr/X11/include/ -o $@ -c $?

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/ fclean && make -C libft/ && $(CC) $(MLX) -o $(NAME)\
		$(OBJ) libft/libft.a -I /usr/X11/include/
		@echo "Fdf compile !" 

clean:
	@rm -f $(OBJ)

cleanlib:
	@make -C libft/ fclean

fclean: clean cleanlib
	@rm -f $(NAME)

re: fclean all
