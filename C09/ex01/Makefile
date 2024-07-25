MY_SOURCES = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = srcs
INC_DIR = includes
SRCS = $(SRC_DIR)/ft_putchar.c \
	   $(SRC_DIR)/ft_swap.c \
	   $(SRC_DIR)/ft_putstr.c \
	   $(SRC_DIR)/ft_strlen.c \
	   $(SRC_DIR)/ft_strcmp.c
OBJS = $(SRCS:.c=.o)

all: $(MY_SOURCES)

$(MY_SOURCES): $(OBJS)
	ar rc $(MY_SOURCES) $(OBJS)
	ranlib $(MY_SOURCES)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(MY_SOURCES)

re: fclean all
