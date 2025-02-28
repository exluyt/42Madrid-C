NAME=do-op
SRCS=srcs/do-op.c srcs/operators.c
OBJS=${SRCS:.c=.o}
CC=cc
CFLAGS=-Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CC} -o ${NAME} ${OBJS}
clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}