# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 17:24:32 by najeuneh          #+#    #+#              #
#    Updated: 2024/11/24 20:14:24 by sadegrae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
ORANGE=\033[38;2;255;165;0m
NC=\033[0m 

CC = cc

MY_SOURCES = src/main.c src/init.c src/ft_split.c src/raycasting/raycasting.c \
				src/check_border.c src/parsing.c src/ft_error.c src/pars_map.c \

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

OBJS_DIR = obj/

SRCS_DIR = src/

NAME = cube3d


INCLUDE = ./inc/philo.h

MY_OBJECTS = $(MY_SOURCES:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

RM = rm -f

all: $(NAME)

$(NAME) : $(MY_OBJECTS)
	@printf "                                               \r"
	@cc $(CFLAGS) -lmlx -framework OpenGL -framework Appkit $(MY_OBJECTS) -o $(NAME)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/raycasting
	$(CC) $(CFLAGS) -I/inc/ -g -o $@ -c $<

debug: $(MY_OBJECTS)
	@gcc -fsanitize=address -g $(MY_OBJECTS) -I/inc/ -o $(NAME)
	
clean:
	@${RM} ${MY_OBJECTS}


fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: fclean re clean all
