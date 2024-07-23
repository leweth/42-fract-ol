CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = fractol

SRCS = utils/utils.c utils/validate_input.c utils/atod.c utils/rendering_utils.c utils/error_utils.c \
		utils/zoom_utils.c utils/exit_utils.c utils/drawing_options.c fractol.c

OBJS = ${SRCS:.c=.o}

LINKFLAGS = -framework Cocoa -framework OpenGL -framework IOKit

SMLX = "/Users/mben-yah/Desktop/MLX42/build/libmlx42.a"

HMLX = "/Users/mben-yah/Desktop/MLX42/include/MLX42/MLX42.h"

MLX = "lib/MLX42/libmlx42.a"

GLFW_PATH = "/Users/${USER}/.brew/opt/glfw/lib"

PRINTF = "lib/printf"

LIBFT = "lib/libft"

LIBS = -lglfw -L${GLFW_PATH} ${MLX} -L${PRINTF} -lftprintf -L${LIBFT} -lft -lm


%.o: %.c includes/utils.h
	${CC} ${CFLAGS} -c $< -o $@


all:  ${PRINTF} ${LIBFT} ${SMLX} ${OBJS} ${NAME}


${NAME}: $(OBJS)
	@echo "\033[1;33mBuilding Target...\033[0m"
	${CC} ${CFLAGS} $(OBJS) ${LIBS} -o ${NAME}
	@echo "\033[1;32mTarget Built Successfully!\033[0m"


${LIBFT}:
	@echo "\033[1;33mBuilding libft...\033[0m"
	make -C lib/libft


${PRINTF}: 
	@echo "\033[1;33mBuilding printf...\033[0m"
	make -C lib/printf


${SMLX}:
	@echo "\033[1;33mFetching the MLX header...\033[0m"
	@cp $(HMLX) includes/
	@echo "\033[1;33mFetching the MLX library...\033[0m"
	@cp ${SMLX} ./lib/MLX42/


clean:
	@echo "\033[1;33mRemoving Object files...\033[0m"
	make -C lib/printf clean
	make -C lib/libft clean
	rm includes/MLX42.h
	rm ${OBJS}


fclean: clean
	@echo "\033[1;33mRemoving libraries and program...\033[0m"
	rm ${NAME}
	rm ${MLX}
	make -C lib/printf fclean
	make -C lib/libft fclean

re: fclean all