CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I./minilibx
LDFLAGS = -L./minilibx -lmlx -lXext -lX11
PRINTF_DIR = ft_printf
SRCS =  ft_show_map.c \
		main.c \
		ft_check_map.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)
NAME = so_long

all: $(NAME)

$(NAME): ft_printf $(OBJS)
	$(MAKE) -C $(PRINTF_DIR)
	cp $(PRINTF_DIR)/libftprintf.a ./libftprintf.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./libftprintf.a $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


ft_printf:
	$(MAKE) -C $(PRINTF_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f libftprintf.a
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all