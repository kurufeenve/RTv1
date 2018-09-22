# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/14 15:52:18 by vordynsk          #+#    #+#              #
#    Updated: 2018/09/14 15:52:19 by vordynsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c init.c render.c
SRC_DIR = ./src/
OBJ_DIR = ./obj/
OBJ = $(addprefix $(OBJ_DIR),$(SRC:.c=.o))
INC = ./includes/rtv1.h
NAME = RTv1
CFLAG = -Werror -Wextra -Wall -O2
FRAMEWORK =  -framework SDL2
FRAMEWORK_PATH = -F /Library/Frameworks
LIBDIR = ./libft
CC = gcc
REMAKE = rmk
$(OBJ_DIR)%.o: %.c $(INC)
		@echo "\033[0;32mCreating object files\033[0m \033[31m$@\033[0m"
		@$(CC) $(CFLAG) $(FRAMEWORK_PATH) -c $< -o $@ -I $(LIBDIR)

all:  $(NAME)
$(NAME): $(OBJ)
		@echo "\033[0;32mCompile solution ...\033[0m"
		@echo "\033[0;32mCompile library ...\033[0m"
		@make -C $(LIBDIR)
		@$(CC) $(CFLAG) -lpthread -o $(NAME) $(OBJ) $(FRAMEWORK_PATH) $(FRAMEWORK) $(LIBDIR)/libft.a
		@echo "\033[0;32mProgram compiled : \033[0m\033[31m$(NAME)\033[0m"
		
$(OBJ): | $(OBJ_DIR)
$(OBJ_DIR):
		@mkdir $(OBJ_DIR)
clean:
		@echo "\033[0;32mCleaning object files ...\033[0m"
		@make clean -C $(LIBDIR)
		@rm -rf $(OBJ_DIR)
		@rm -f $(OBJ)
fclean: clean
		@make fclean -C $(LIBDIR)
		@rm -f $(NAME)
		@echo "\033[31m$(NAME)\033[0m\033[0;32m was completely removed\033[0m"
re: $(REMAKE) fclean all
$(REMAKE):
		@echo "\033[0;32mRemaking project \033[0m\033[31m$(NAME)\033[0m" 
vpath %.c $(SRC_DIR)
