CC = cc
CFLAGS = -Wall -Wextra -Werror
PRINTF_DIR = ft_printf
SRCS =	main.c \
		operaciones.c \
		operaciones_rotate.c \
		rrr.c \
		alghoritm.c \
		alghoritm_utils.c \
		alghoritm_utils2.c \
		alghoritm_utils3.c \
		alghoritm_utils4.c \
		free.c \

OBJS = $(SRCS:.c=.o)
NAME = push_swap

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