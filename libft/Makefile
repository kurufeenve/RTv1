# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 13:27:38 by vordynsk          #+#    #+#              #
#    Updated: 2017/10/30 13:33:36 by vordynsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = includes/libft.h

OFILES = ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o \
		ft_isprint.o ft_itoa.o ft_memalloc.o ft_memccpy.o ft_memchr.o ft_memcmp.o \
		ft_memcpy.o ft_memdel.o ft_memmove.o ft_memset.o ft_putchar.o ft_putchar_fd.o \
		ft_putendl.o ft_putendl_fd.o ft_putnbr.o ft_putnbr_fd.o ft_putstr.o ft_putstr_fd.o \
		ft_strcat.o ft_strchr.o ft_strclr.o ft_strcmp.o ft_strcpy.o ft_strdel.o \
		ft_strdup.o ft_strequ.o ft_striter.o ft_striteri.o ft_strjoin.o ft_strlcat.o \
		ft_strlen.o ft_strmap.o ft_strmapi.o ft_strncat.o ft_strncmp.o ft_strncpy.o \
		ft_strnequ.o ft_strnew.o ft_strnstr.o ft_strrchr.o ft_strsplit.o ft_strstr.o \
		ft_strsub.o ft_strtrim.o ft_tolower.o ft_toupper.o ft_lstnew.o ft_lstmap.o \
		ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o ft_arrtozero.o ft_newarrtozero.o \
		ft_printarr.o ft_realloc.o get_next_line.o ft_memkill.o ft_lstaddend.o ft_isnumber.o \
		ft_chararrdel.o ft_itoa_base.o ft_qpow.o ft_vector_length.o ft_vec_add.o ft_vec_sub.o \
		ft_int_arr.o ft_size_t_arr.o ft_strrev.o ft_strjoin2.o ft_delwhitesp.o ft_strfind.o \
		ft_strnfind.o ft_indexof.o ft_strnsub.o ft_atoi_base.o

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILES)
	@ar rc $(NAME) $(OFILES)
	@ranlib $(NAME)

%.o : %.c
	@gcc $(FLAG) -c -o $@ $< -I $(HEADER)

clean:
	@rm -rf $(OFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all
