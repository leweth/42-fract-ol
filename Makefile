CC = gcc

CFLAGS = -Wall -Wextra -Werror

LINKFLAGS = -framework Cocoa -framework OpenGL -framework IOKit

SMLX = "/Users/mben-yah/Desktop/MLX42/build/libmlx42.a"

MLX = "./lib/MLX42/libmlx42.a"

NAME = fractol

GLFW_PATH = "/Users/${USER}/.brew/opt/glfw/lib"

# SRCS = # Path to the utilities files that are within the utils directory

OBJS = ${SRCS:.c=.o}

PRINTF = "./lib/printf"


%.o: %.c utils.h
	${CC} ${CFLAGS} -c $< -o $@


all: ${NAME}


${NAME}: ${PRINTF} ${SMLX} ${OBJS}
	@echo "\033[1;33mBuilding Target...\033[0m"
	${CC} ${CFLAGS} fractol.c -lglfw -L${GLFW_PATH} ${MLX} ${OBJS} -L${PRINTF} -lftprintf  -o ${NAME}
	@echo "\033[1;32mTarget Built Successfully!\033[0m"


${PRINTF}: 
	@echo "\033[1;33mBuilding printf...\033[0m"
	cd ./lib/printf && ${MAKE}


${SMLX}:
	@echo "\033[1;33mFetching the MLX library...\033[0m"
	echo $(SMLX)
	@cp ${SMLX} ./lib/MLX42/


clean:
	@echo "\033[1;33mRemoving Object files...\033[0m"
	rm ./utils/${OBJS}
	rm ${MLX}
	cd ./lib/printf && ${MAKE} clean


fclean: clean
	@echo "\033[1;33mRemoving libraries and program...\033[0m"
	rm ${NAME}
	cd ./lib/printf && ${MAKE} fclean


re: fclean ${NAME}