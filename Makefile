# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyu <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/27 19:29:57 by hyu               #+#    #+#              #
#    Updated: 2020/01/31 21:27:32 by hyu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf

SRCS=./srcs/deal_key.c \
	 ./srcs/get_next_line.c \
	 ./srcs/input_check.c \
	 ./srcs/linked_list.c \
	 ./srcs/read_file.c \
	 ./srcs/rescale.c \
	 ./srcs/scaling.c \
	 ./srcs/t_scaler.c \
	 ./srcs/word_spacecheck.c \
	 ./srcs/twodim_linked_list.c\
	 ./srcs/hex.c\
	 ./srcs/str_join.c
	  
OBJECTS=deal_key.o \
     get_next_line.o \
     input_check.o \
	 linked_list.o \
	 read_file.o \
     rescale.o \
     scaling.o \
     t_scaler.o \
     word_spacecheck.o \
	 twodim_linked_list.o\
	 hex.o\
	 str_join.o

INCLUDES=-I minilibx/ -I libft/ -I INCLUDES/
FLAGS= -g -Wall -Werror -Wextra

LIBFT=-L libft -l ft
FRAMEWORK=-framework OpenGL -framework Appkit
MLX=-L ~/Desktop/minilibx_macos -l mlx

all: $(NAME)

$(NAME):
	make -C libft
	make -C minilibx
	gcc -c $(FLAGS) $(SRCS)
	ar -rv fdf.a $(OBJECTS)
	ranlib fdf.a
	gcc -g minilibx/libmlx.a libft/libft.a fdf.a -framework OpenGL -framework Appkit main.c -o $(NAME)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -f $(NAME)
	
re:fclean all
