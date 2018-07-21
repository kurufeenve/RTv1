# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/26 17:16:22 by vordynsk          #+#    #+#              #
#    Updated: 2018/04/26 17:16:24 by vordynsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

HEADER = rtv1.h

SRC = main.c

SRCDIR = src

OBJDIR = obj

SRCP = $(addprefix $(SRCDIR)/,$(SRC))

OBJ = $(patsubst %.c, %.o, $(SRC))

OBJP = $(addprefix $(OBJDIR)/,$(OBJ))

CC = gcc

LIBPATH = -C libft/

LIBRARY = libft/libft.a

FLAGS = -g -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	make $(LIBPATH)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) -I $(HEADER) $(LIBRARY)

%.o : $(SRCDIR)/%.c
	$(CC) -c $< -o $@ -I $(HEADER)

clean:
	$(MAKE) clean $(LIBPATH)
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) $(LIBRARY)

re: fclean all
