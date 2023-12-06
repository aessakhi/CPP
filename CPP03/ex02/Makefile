# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 17:41:55 by aessakhi          #+#    #+#              #
#    Updated: 2022/07/25 17:42:14 by aessakhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp \
		main.cpp

OBJS = $(SRCS:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = FragTrap

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
