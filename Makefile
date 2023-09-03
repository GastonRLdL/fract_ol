# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: groman-l <groman-l@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/01 21:35:34 by groman-l          #+#    #+#              #
#    Updated: 2023/09/03 15:38:35 by groman-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~VARIABLES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
NAME = fractol
CC = gcc
RM = rm -rf
LIBC = ar -rcs
FLAGS = -Wall -Wextra -Werror -O3 -g
MN_LIB = ./miniLibX/
FRAME = -framework OpenGL -framework AppKit

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~SORUCES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
SRC = fract_ol.c render.c
L_SRC = ./src
L_ML = ./miniLibX/libmlx.a
INC =	-I ./inc/\
		-I ./miniLibX/\

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~DIRECTORIES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
D_OBJ = $(L_SRC)/obj
OBJ = $(addprefix $(D_OBJ)/, $(SRC:.c=.o))
DEP = $(addprefix $(D_OBJ)/, $(SRC:.c=.d))

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MAKE RULES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
all: dir $(NAME)

-include $(DEP)

dir:
	@make -C $(MN_LIB) --no-print-directory &> /dev/null
	@mkdir -p $(D_OBJ)

$(D_OBJ)/%.o: $(L_SRC)/%.c
	@$(CC) -MMD $(FLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(L_ML) $(FRAME) -o $(NAME) $(INC)

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CLEAN~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
.PHONY: clean fclean re

fclean: clean
	$(RM) $(NAME) $(NAME)

clean:
	$(RM) $(D_OBJ)
	@make clean -C $(MN_LIB) --no-print-directory

re: fclean all
.SILENT: