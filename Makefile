CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = fractol

SRCS = # Path to the utilities files that are within the utils directory

OBJS = ${SRCS:.c=.o}

UTILS = libutils.a

PRINTF = libftprintf.a


%.o: %.c utils.h
	${CC} ${CFLAGS} -c $< -o $@


all: ${NAME}


${NAME}:
	${CC} ${CFLAGS} fractol.c -L. -lutils -lprintf -o ${NAME}


${UTILS}: ${OBJS}
	ar rsc ${UTILS} ${OBJS}

${PRINTF}: 
	cd printf && ${MAKE}
	cp ./printf/${PRINTF} .

clean:
	rm ${OBJS}
	cd printf && ${MAKE} clean

fclean: clean
	rm ${NAME}
	cd printf && ${MAKE} fclean

re: fclean ${NAME}