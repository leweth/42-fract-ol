CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = fractol

SRCS = utils/utils.c utils/validate_input.c utils/atod.c utils/rendering_utils.c utils/error_utils.c \
		utils/zoom_utils.c utils/exit_utils.c

OBJS = ${SRCS:.c=.o}

LINKFLAGS = -framework Cocoa -framework OpenGL -framework IOKit

SMLX = "/Users/mben-yah/Desktop/MLX42/build/libmlx42.a"

MLX = "lib/MLX42/libmlx42.a"

GLFW_PATH = "/Users/${USER}/.brew/opt/glfw/lib"

PRINTF = "lib/printf"

LIBFT = "lib/libft"

LIBCMPLX =  "lib/libcmplx"

LIBS = -lglfw -L${GLFW_PATH} ${MLX} ${OBJS} -L${PRINTF} -lftprintf -L${LIBFT} -lft -L${LIBCMPLX} -lcmplx -lm


%.o: %.c utils.h
	${CC} ${CFLAGS} -c $< -o $@


all: ${NAME}


${NAME}: ${PRINTF} ${SMLX} ${LIBFT} ${OBJS} ${LIBCMPLX}
	@echo "\033[1;33mBuilding Target...\033[0m"
	${CC} ${CFLAGS} fractol.c ${LIBS} -o ${NAME}
	@echo "\033[1;32mTarget Built Successfully!\033[0m"


${LIBFT}:
	@echo "\033[1;33mBuilding libft...\033[0m"
	cd  lib/libft && ${MAKE}


${PRINTF}: 
	@echo "\033[1;33mBuilding printf...\033[0m"
	cd lib/printf && ${MAKE}


${LIBCMPLX}:
	@echo "\033[1;33mBuilding libcmplx...\033[0m"
	cd lib/libcmplx && ${MAKE}


${SMLX}:
	@echo "\033[1;33mFetching the MLX library...\033[0m"
	echo $(SMLX)
	@cp ${SMLX} ./lib/MLX42/


clean:
	@echo "\033[1;33mRemoving Object files...\033[0m"
	cd lib/printf && ${MAKE} clean
	cd lib/libft && ${MAKE} clean
	cd lib/libcmplx && ${MAKE} clean
	rm ${OBJS}


fclean: clean
	@echo "\033[1;33mRemoving libraries and program...\033[0m"
	rm ${NAME}
	rm ${MLX}
	cd lib/printf && ${MAKE} fclean
	cd lib/libft && ${MAKE} fclean
	cd lib/libcmplx && ${MAKE} fclean

re: fclean ${NAME}