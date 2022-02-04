# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 16:53:40 by mcarecho          #+#    #+#              #
#    Updated: 2021/10/05 10:39:45 by mcarecho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./get_next_line
CC = gcc

SRCS = example_main.c get_next_line.c get_next_line_utils.c

CFLAGS = -D BUFFER_SIZE=1

all: $(NAME)
	${CC} ${CFLAGS} -g  ${SRCS} -o get_next_line


.PHONY: all
