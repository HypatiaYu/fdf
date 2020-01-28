# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyu <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/27 19:29:57 by hyu               #+#    #+#              #
#    Updated: 2020/01/27 19:43:09 by hyu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf.a

SRCS=deal_key.c\
	 get_next_line.c\
	 input_check.c\
	 linked_list.c\
	 read_file.c\
	 rescale.c\
	 scaling.c\
	 t_scaler.c\
	 word_spacecheck.c
	  
OBJECTS=deal_key.o\
     get_next_line.o\
     input_check.o\
	 linked_list.o\
	 read_file.o\
     rescale.o\
     scaling.o\
     t_scaler.o\
     word_spacecheck.o

INCLUDES=./

LIB =libft/libft.a

FLAG=-lmlx -framework OpenGL -framework AppKit

all: $(NAME)
$(NAME): fdf.h
	cc -I ~/Desktop/minilibx_macos main.c -L ~/Desktop/minilibx_macos $(FLAG) $(LIB) -c $(SRCS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re:fclean all
