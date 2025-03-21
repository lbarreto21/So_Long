CC = cc

CFLAGS =  -g -Wall -Werror -Wextra

SRCS = main.c	\
handle_map.c	\
utils.c	\
utils2.c	\
verification_utils.c	\
handle_window.c	\
handle_sprites.c	\
handle_movements.c

NAME = so_long

LIB = libft/libft.a

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	make -C minilibx-linux
	$(CC) $(OBJS) -lmlx_Linux -L./minilibx-linux -lXext -lX11 -lm -o $(NAME) $(LIB)

.c.o:
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	make clean -C libft
	make clean -C minilibx-linux
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean $(NAME)

norm:
	norminette *.c
