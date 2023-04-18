# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thovan-d <thovan-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 12:35:08 by thovan-d          #+#    #+#              #
#    Updated: 2023/04/18 13:53:47 by thovan-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	so_long

LIBMLX	=	./MLX42

SRC 	= 	ft_printf.c ft_writetypes.c ft_hex.c get_next_line.c get_next_line_utils.c so_long.c find_make_map.c map_checker.c map_checker2.c flood_fill.c moves.c window.c free_and_delete.c

GCC		=	gcc

FLAG	=	-Wall -Werror -Wextra

HEADER	=	-I $(LIBMLX)/include/MLX42

LIBS	=	$(LIBMLX)/build/libmlx42.a -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit

OBJS	=	${SRC:.c=.o}

# AR		= ar -rc

all: libmlx ${NAME}

${NAME}: ${OBJS}
	# @${MAKE} -C MLX42/build
	${CC} ${OBJS} ${LIBS} ${HEADER} ${FLAG} -o ${NAME}

libmlx:	
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

${OBJS}: ${SRC}
	${GCC} ${FLAG} -c ${SRC}

clean:
	rm -f ${OBJS}
	@${MAKE} -C $(LIBMLX)/build clean

fclean:		clean
	rm -f ${NAME}
	rm -rf ${LIBMLX}/build

re:		fclean all

.PHONY: bonus all clean fclean re libmlx