# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnqabash <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/21 14:17:54 by lnqabash          #+#    #+#              #
#    Updated: 2018/09/21 15:43:46 by lnqabash         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

OBJ_PATH = ./obj/
LIBFT_PATH = ./libft/
INC_PATH = ./includes/
SRC_PATH = ./src/

LFOFA = -lmlx -framework OpenGL -framework AppKit
INC_NAME = wolf3d
SRC_NAME = main.c draw.c read.c key_func.c
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all : $(NAME)

$(NAME): $(OBJ)
		@make -C $(LIBFT_PATH)
		@$(CC) -o $(NAME) $(LFOFA) -L $(LIBFT_PATH) -lft $^ -o $@
		@echo "                                                 "
		@echo "* * * * * * * * * * * * * * *" 
		@echo "*	This is how to run the program"
	   	@echo "*        ./wolf3d "your name""
		@echo "*"	

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		@mkdir -p $(OBJ_PATH) 2> /dev/null || true
		@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean: 
		@rm -rf $(OBJ_PATH)
		@make -C $(LIBFT_PATH) clean

fclean: clean
		@rm -rf $(NAME)
		@make -C $(LIBFT_PATH) fclean

re: fclean all
