NAME	:=	cub3d

SRCS	:=	src/main.c \
			src/engine/init.c \
			src/engine/pixel_put.c \
			src/engine/raycasting.c \
			src/engine/rendering.c \
			src/engine/utils.c \
			src/engine/vectors.c \
			src/engine/collisions.c \
			src/engine/event_handling.c \
			src/engine/textures.c\
			src/parsing/2d_array_utils.c\
			src/parsing/check_flor_ceiling_colour.c\
			src/parsing/input_prep.c\
			src/parsing/utils.c\
			src/parsing/check_map_surrounded.c\
			src/parsing/xpm_to_int_arr.c\
			src/parsing/xpm_to_int_arr_utils.c

OBJS	:=	${SRCS:.c=.o}

CC		:=	gcc

CFLAGS	:=	-Wall -Wextra -Wextra -O3



all:		${NAME}

%.o: %.c
		${CC} ${CFLAGS} -Imlx -c $< -o $@

${NAME}:	${OBJS}
		@make -C ./libft
		@make -C ./get_next_line all
		@make -C ./mlx all
		@${CC} ${OBJS} ${CFLAGS} libft/libft.a get_next_line/get_next_line.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

clean:
		@make -C ./libft clean
		@make -C ./get_next_line clean
		@make -C ./mlx clean
		rm -f ${OBJS} ${FPS_OBJS}

fclean:		clean
		@make -C ./libft fclean
		@make -C ./get_next_line fclean
		rm -f ${NAME} ${FPS_NAME}

re:			fclean all

.PHONY:		all clean fclean re