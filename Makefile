# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsedat <vsedat@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 15:08:55 by vsedat            #+#    #+#              #
#    Updated: 2022/01/21 16:58:08 by vsedat           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

##**********##
### COLORS ###
##**********##
NOC			= \033[0m
BOLD		= \033[1m
UNDERLINE	= \033[4m
BLACK		= \033[1;30m
RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
VIOLET		= \033[1;35m
CYAN		= \033[1;36m
WHITE		= \033[1;37m

##********##
### NAME ###
##********##
NAME	= fractol

##***************##
### COMPILATION ###
##**************###
CC		= gcc -Ofast
CFLAGS	= -Wall -Wextra -Werror
CMLX	= -framework OpenGL -framework AppKit -g -lmlx -Lmlx

##************##
### INCLUDES ###
##************##
HEADER		= incl
MLX			= mlx
OBJ_PATH	= objs
SRC_PATH	= srcs

##***********##
### OBJECTS ###
##***********##
SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

##****************##
### SOURCE FILES ###
##****************##
SOURCES	= fractol.c	\

##*********##
### RULES ###
##*********##
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)/$(NAME).h
			${CC} ${CFLAGS} ${CMLX} -c $< -o ${<:.c=.o}

all: 	${NAME}
		@make -C ${MLX}

test:
			@echo "$(GREEN)ඞ this test is sus ඞ$(CYAN)"
			@echo "$(BLUE)click to draw, click again to pause$(CYAN)"
			@echo "$(BLUE)press C to erase and ECHAP to quit$(CYAN)"
			@${CC} ${CMLX} ${SRCS} -o ${NAME}
			@./${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${CMLX} -o ${NAME} ${OBJS}

clean:
		rm -f ${OBJS}

fclean:	clean
		rm -rf ${NAME} 

re:	fclean all

retest:	fclean test

.PHONY:	all clean fclean re test retest
