CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = c_sum.c c_pow.c c_magnitude.c c_mult.c

OBJS = ${SRCS:.c=.o}

NAME = libcmplx.a


%.o: %.c ft_complex.h
	${CC} ${CFLAGS} -c $< -o $@


${NAME}: ${OBJS}
	@ar rsc ${NAME} ${OBJS}
	
all: ${NAME}

clean:
	@${RM} -rf ${OBJS} 

fclean: clean
	@rm -rf ${NAME}

re: fclean all
