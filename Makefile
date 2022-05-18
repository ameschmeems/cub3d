NAME	:=	cub3d

SRCS	:=	main.c

OBJS	:=	${SRCS:.c=.o}

CC		:=	gcc

CFLAGS	:=	-Wall -Wextra -Werror

all:		${NAME}

%.o: %.c
		${CC} -Wall -Wextra -Werror -Imlx -c $< -o $@

${NAME}:	${OBJS}
		@make -C ./libft
		${CC} ${OBJS} libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

clean:
		rm -f ${OBJS} ${FPS_OBJS}

fclean:		clean
		rm -f ${NAME} ${FPS_NAME}

re:			fclean all

.PHONY:		all clean fclean re