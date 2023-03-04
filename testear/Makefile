# en este proyecto NO se entrega Makefile

SRCS = main.c get_next_line.c get_next_line_utils.c
# incluir después en lugar de la libft get_next_line_utils.c
OBJS = ${SRCS:.c=.o}

TGT = gnl.out

LIBFT = -L../libft -lft

BUFF = "-D BUFFER_SIZE=20"
#${BUFF}

all:
	gcc -c get_next_line.c ${LIBFT} -lft -o ${TGT}

t:  clean
	gcc ${SRCS} -o ${TGT}

flgs: clean
	gcc -Wall -Wextra -Werror -fsanitize=address -c main.c

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f TGT