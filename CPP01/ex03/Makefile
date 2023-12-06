# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/10 23:47:06 by aessakhi          #+#    #+#              #
#    Updated: 2022/07/10 23:47:56 by aessakhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	Weapon.cpp \
		HumanA.cpp \
		HumanB.cpp \
		main.cpp

OBJS = $(SRCS:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Unnecessary_violence

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