CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
PRINTF_DIR = ft_printf
SRCS =	pipex.c \
		pipex_utils.c \

OBJS = $(SRCS:.c=.o)
NAME = pipex

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