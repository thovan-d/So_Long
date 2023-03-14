# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thovan-d <thovan-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 12:35:08 by thovan-d          #+#    #+#              #
#    Updated: 2023/03/14 18:08:50 by thovan-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long.a

SRC 	= 	ft_printf.c ft_writetypes.c ft_hex.c get_next_line.c get_next_line_utils.c so_long.c find_make_map.c map_checker.c map_checker2.c

GCC		=	gcc

FLAG	= -Wall -Werror -Wextra

OBJS	=	${SRC:.c=.o}

AR		= ar -rc

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

all: ${NAME}

${OBJS}: ${SRC}
	${GCC} ${FLAG} -c ${SRC}

clean:
	rm -f ${OBJS}

fclean:		clean
	rm -f ${NAME}

re:		fclean all

.PHONY: bonus all clean fclean re