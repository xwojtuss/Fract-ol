CC = cc

CFLAGS = -Wall -Wextra -Werror -O3

INCLUDES = -Iincludes -I${MLX_DIR} -I${LIBFT_DIR}

LIBFT_REPO = https://github.com/xwojtuss/Libft.git
LIBFT_NAME = libft.a
LIBFT_DIR = libs/Libft

MLX_REPO = https://github.com/42Paris/minilibx-linux.git
MLX_NAME = libmlx.a
MLX_DIR = libs/mlx_linux

LIBS = ${MLX_DIR}/${MLX_NAME} ${LIBFT_DIR}/${LIBFT_NAME} -lm -lX11 -lXext

NAME = fractol

SRCS = main.c exit_controllably.c mandelbrot.c put_pixel.c \
	hooks.c display.c initialize.c draw_loop.c complex.c \
	julia.c burningship.c zoom.c

SRCS_DIR = srcs

SRCS_FILES = ${addprefix ${SRCS_DIR}/,${SRCS}}

OBJS = ${SRCS_FILES:.c=.o}

all: ${NAME} ${NAME_BONUS}

bonus: ${NAME_BONUS}

${NAME}: ${MLX_DIR}/${MLX_NAME} ${LIBFT_DIR}/${LIBFT_NAME} ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS} ${INCLUDES}

${SRCS_DIR}/%.o: ${SRCS_DIR}/%.c
	${CC} ${CFLAGS} -c $< -o $@ ${INCLUDES}

${LIBFT_DIR}/${LIBFT_NAME}:
	@if [ ! -d ./${LIBFT_DIR} ]; then \
		git clone ${LIBFT_REPO} ${LIBFT_DIR}; \
		echo "Cloning Libft repository"; \
	fi
	@if [ ! -f ./${LIBFT_DIR}/${LIBFT_NAME} ]; then \
		make -C ${LIBFT_DIR}; \
		echo "Running make for Libft"; \
	fi

${MLX_DIR}/${MLX_NAME}:
	@if [ ! -d ./${MLX_DIR} ]; then \
		git clone ${MLX_REPO} ${MLX_DIR}; \
		echo "Cloning Libft repository"; \
	fi
	@if [ ! -f ./${MLX_DIR}/${MLX_NAME} ]; then \
		make -C ${MLX_DIR}; \
		echo "Running make for Libft"; \
	fi

clean:
	rm -f ${OBJS}
	@if [ -d ./${LIBFT_DIR} ]; then \
		make clean -C ${LIBFT_DIR}; \
	fi
	@if [ -d ./${MLX_DIR} ]; then \
		make clean -C ${MLX_DIR}; \
	fi

fclean: clean
	rm -f ${NAME}
	@if [ -d ./${LIBFT_DIR} ]; then \
		make fclean -C ${LIBFT_DIR}; \
	fi
	rm -f ${MLX_DIR}/${MLX_NAME}

re: fclean all

fullclean: fclean
	rm -rf ${LIBFT_DIR} ${MLX_DIR}

rebuild: fullclean all

reclone:
	rm -rf ${LIBFT_DIR} ${MLX_DIR}
	make all

.PHONY: all clean fclean fullclean re rebuild reclone
