# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 17:21:31 by aessakhi          #+#    #+#              #
#    Updated: 2022/07/25 17:22:04 by aessakhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	Fixed.cpp \
		main.cpp

OBJS = $(SRCS:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Fixed

RM = rm -rf

all: ${NAME}

$(NAME):	${OBJS}
	c++ -o ${NAME} ${SRCS} ${CFLAGS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONE: all clean fclean re
