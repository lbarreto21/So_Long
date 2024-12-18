CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = main.c	\
handle_map.c	\
utils.c

NAME = so_long

LIB = libft/libft.a

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -g -lmlx_Linux -L./minilibx-linux -lXext -lX11 -lm -o $(NAME) $(LIB)

.c.o:
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean: 
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
