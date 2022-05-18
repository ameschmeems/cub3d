NAME	:=	cub3d

SRCS	:=	src/main.c

OBJS	:=	${SRCS:.c=.o}

CC		:=	gcc

CFLAGS	:=	

all:		${NAME}

%.o: %.c
		${CC}  -Imlx -c $< -o $@

${NAME}:	${OBJS}
		@make -C ./libft
		${CC} ${OBJS} libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

clean:
		rm -f ${OBJS} ${FPS_OBJS}

fclean:		clean
		rm -f ${NAME} ${FPS_NAME}

re:			fclean all

.PHONY:		all clean fclean re