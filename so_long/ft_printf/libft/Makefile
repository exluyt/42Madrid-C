NAME = libft.a
CC = cc
GET_NEXT_DIR = get_next_line
CFLAGS = -Wall -Wextra -Werror
SRCS =  ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isdigit.c \
		ft_isalpha.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_memcpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_substr.c \
		ft_striteri.c
		
OBJS = $(SRCS:.c=.o)

SRCS_BONUS = ft_lstnew_bonus.c \
			 ft_lstadd_front_bonus.c \
			 ft_lstsize_bonus.c \
			 ft_lstlast_bonus.c \
			 ft_lstadd_back_bonus.c \
			 ft_lstdelone_bonus.c \
			 ft_lstclear_bonus.c \
			 ft_lstiter_bonus.c \
			 ft_lstmap_bonus.c

SRC_GET = $(GET_NEXT_DIR)/get_next_line.c $(GET_NEXT_DIR)/get_next_line_utils.c

OBJS_GET = $(SRC_GET:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

$(NAME):  get_next_line $(OBJS) $(OBJS_BONUS) $(OBJS_GET)
	ar rc $(NAME) $(OBJS) $(OBJS_BONUS) $(OBJS_GET)
	ranlib $(NAME)
	touch bonus.bonus

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus: bonus.bonus

bonus.bonus: $(OBJS_BONUS)
	ar rc $(NAME) $(OBJS_BONUS)
	ranlib $(NAME)
	touch bonus.bonus

clean:
	rm -f $(OBJS) $(OBJS_BONUS) $(OBJS_GET) bonus.bonus

fclean: clean
	rm -f $(NAME)

re: fclean all bonus