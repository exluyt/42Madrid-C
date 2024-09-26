CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
LIBFT_DIR = libft
SRCS =	ft_printf.c \
		ft_putaddr.c \
		ft_putchar.c \
		ft_puthex_lo_fd.c \
		ft_puthex_up_fd.c \
		ft_putnbr.c \
		ft_putstr.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): libft $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/libft.a ./$(NAME)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

libft:
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
