CC = gcc

CFLAGS = -Wall -Wextra -Werror

LINKFLAGS = -framework Cocoa -framework OpenGL -framework IOKit

MLX = ./lib/MLX/libmlx42.a

NAME = fractol

GLFW_PATH = "/Users/${USER}/.brew/opt/glfw/lib"

# SRCS = # Path to the utilities files that are within the utils directory

OBJS = ${SRCS:.c=.o}

PRINTF = "./lib/printf"


%.o: %.c utils.h
	${CC} ${CFLAGS} -c $< -o $@


all: ${NAME}


${NAME}: ${OBJS} ${PRINTF}
	@echo "\033[1;33mBuilding Target...\033[0m"
	${CC} ${CFLAGS} example.c -lglfw -L${GLFW_PATH} ${MLX} ${OBJS} -L${PRINTF} -lftprintf  -o ${NAME}
	@echo "\033[1;32mTarget Built Successfully!\033[0m"


${PRINTF}: 
	@echo "\033[1;33mBuilding printf...\033[0m"
	cd ./lib/printf && ${MAKE}


clean:
	@echo "\033[1;33mRemoving Object files...\033[0m"
	rm ./utils/${OBJS}
	cd ./lib/printf && ${MAKE} clean


fclean: clean
	@echo "\033[1;33mRemoving libraries and program...\033[0m"
	rm ${NAME}
	cd ./lib/printf && ${MAKE} fclean


re: fclean ${NAME}