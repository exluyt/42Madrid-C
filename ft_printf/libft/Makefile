MY_SOURCES = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = libft.h
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
		ft_substr.c
OBJS = $(SRCS:.c=.o)

SRCS_BONUS = ft_lstnew_bonus.c \
			 ft_lstadd_front_bonus.c \
			 ft_lstsize_bonus.c \
			 ft_lstlast_bonus.c \
			 ft_lstadd_back_bonus.c \
			 ft_lstdelone_bonus.c \
			 ft_lstclear_bonus.c 

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(MY_SOURCES)

$(MY_SOURCES): $(OBJS) $(INCLUDE)
	ar rcs $(MY_SOURCES) $(OBJS)
	ranlib $(MY_SOURCES)

bonus: $(OBJS) $(OBJS_BONUS) $(INCLUDE)
	ar rcs $(MY_SOURCES) $(OBJS_BONUS) $(OBJS)
	ranlib $(MY_SOURCES)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(MY_SOURCES)

re: fclean all bonus