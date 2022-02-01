# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsedat <vsedat@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 15:08:55 by vsedat            #+#    #+#              #
#    Updated: 2022/02/01 14:37:09 by vsedat           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

##**********##
### COLORS ###
##**********##
BLACK		= \033[1;30m
RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
VIOLET		= \033[1;35m
CYAN		= \033[1;36m
WHITE		= \033[1;37m
IGREY		= \x1b[40m
IRED		= \x1b[41m
IGREEN		= \x1b[42m
IYELLOW		= \x1b[43m
IBLUE		= \x1b[44m
IPURPLE		= \x1b[45m
ICYAN		= \x1b[46m
IWHITE		= \x1b[47m
END			= \x1b[0m
UNDERLINE	= \x1b[4m
REV			= \x1b[7m

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

##*************##
### DIR PATHS ###
##*************##
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
SOURCES	=	fractol.c	\
			commands.c	\
			init.c		\
			color.c		\
			forms.c		\
			parsing.c	\

##*********##
### RULES ###
##*********##
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)/$(NAME).h
			${CC} ${CFLAGS} ${CMLX} -c $< -o ${<:.c=.o}

all: 	${NAME}
		@make -C ${MLX}

test:
			@echo "$(GREEN)ඞ this test is sus ඞ$(RED)"
			${CC} ${CMLX} ${SRCS} -o ${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${CMLX} -o ${NAME} ${OBJS}

mandelbrot:	test
			./fractol mandelbrot
			
julia:	test
		./fractol julia
		
clean:
		rm -f ${OBJS}

fclean:	clean
		rm -rf ${NAME} 

re:	fclean all

retest:	fclean test

.PHONY:	all clean fclean re test retest
