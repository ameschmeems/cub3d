NAME	:=	cub3d

SRCS	:=	src/main.c \
			src/engine/init.c \
			src/engine/pixel_put.c \
			src/engine/raycasting.c \
			src/engine/rendering.c \
			src/engine/utils.c \
			src/engine/vectors.c \
			src/engine/collisions.c \
			src/engine/event_handling.c

OBJS	:=	${SRCS:.c=.o}

CC		:=	gcc

CFLAGS	:=	-Wall -Wextra -g

all:		${NAME}

%.o: %.c
		${CC} ${CFLAGS} -Imlx -c $< -o $@

${NAME}:	${OBJS}
		@make -C ./libft
		${CC} ${OBJS} ${CFLAGS} libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

clean:
		rm -f ${OBJS} ${FPS_OBJS}

fclean:		clean
		rm -f ${NAME} ${FPS_NAME}

re:			fclean all

.PHONY:		all clean fclean re