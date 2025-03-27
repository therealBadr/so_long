NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./MLX1 -I ./MLX1/include
MLX_FLAGS = -L ./MLX1 -lmlx -lXext -lX11 -lm -lz

SRCS =	main.c \
	parsing.c \
	checks.c \
	belongs_to_set.c \
	ft_arrlen.c \
	ft_split.c \
	ft_strcmp.c \
	get_next_line.c \
	get_next_line_utils.c \
	rendering.c \
	error_handling.c \
	moves_cases.c \
	moves.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re