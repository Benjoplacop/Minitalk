# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 18:19:08 by bhennequ          #+#    #+#              #
#    Updated: 2023/03/06 15:52:12 by bhennequ         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFTNAME = libft.a

SERVER= server

CLIENT= client

LIBFTDIR = libft

CC = gcc

SRCSERV = server.c

SRCCLIENT = client.c

CFLAGS = -Wall -Wextra -Werror

OBJSERV = ${SRCSERV:.c=.o}
	  
OBJCLIENT = ${SRCCLIENT:.c=.o}

all: ${CLIENT} ${SERVER}

${SERVER}: ${OBJSERV}
		${CC} -o ${SERVER} ${OBJSERV} libft/libft.a

${CLIENT}: ${OBJCLIENT}
		${CC} -o ${CLIENT} ${OBJCLIENT} libft/libft.a
clean:
	rm -f ${OBJCLIENT} ${OBJSERV}
	cd ${LIBFTDIR} && make clean

fclean: clean
	rm -f ${SERVER} ${CLIENT}

re: fclean all
