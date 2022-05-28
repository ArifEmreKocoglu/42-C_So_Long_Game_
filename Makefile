NAME	= so_long

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

SRCS	= ./so_long.c \
			./so_long_add_image.c \
			./so_long_move.c \
			./so_long_validation.c \
			./so_long_another_valid.c \
			./get_nextline/get_next_line.c \
			./get_nextline/get_next_line_utils.c \

OBJS	= $(SRCS:%.c=%.o)

$(NAME):$(OBJS)
		make -C ./mlx
		mv ./mlx/libmlx.a ./libmlx.a

		make -C ./printf/libft
		mv ./printf/libft/libft.a ./libft.a

		make -C ./printf
		mv ./printf/libftprintf.a ./libftprintf.a

		$(CC) $(CFLAGS) $(SRCS) -framework OpenGL -framework AppKit libmlx.a libft.a libftprintf.a -o $(NAME)
all: 	$(NAME)

clean:
		make -C ./mlx clean
		rm -rf */*.o libmlx.a so_long.o so_long_add_image.o so_long_move.o so_long_validation.o so_long_another_valid.o

		rm -rf ${NAME}

fclean: clean
		make -C ./printf/libft fclean
		rm -rf */*.o libft.a

		make -C ./printf fclean
		rm -rf */*.o libftprintf.a

re: 	fclean all

.PHONY: all clean re
