NAME	=	fdf
SRC	=	main.c key_hook.c create_map.c mod_line.c ft_fill_map.c
OBJ	=	$(SRC:.c=.o)
HDR	=	libft/includes/
MLX	=	-I includes libft/libft.a  -Lminilibx -lmlx -framework OpenGL -framework AppKit -I minilibx/
FLAGS	=	-Wall -Wextra -Werror
CC	=	gcc

%.o: %.c
	@$(CC) -I ./includes -I /usr/X11/include/ -o $@ -c $?

all: $(NAME)

$(NAME): $(OBJ)
	   @make -C libft/ fclean && make -C libft/ && $(CC) $(MLX) -o $(NAME)\
		$(OBJ) libft/libft.a -I /usr/X11/include/ -ggdb
		@echo "Fdf compile !" 

clean:
	@rm -f $(OBJ)

cleanlib:
	@make -C libft/ fclean

fclean: clean cleanlib
	@rm -f $(NAME)

re: fclean all
