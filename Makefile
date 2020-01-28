# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyu <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/27 19:29:57 by hyu               #+#    #+#              #
#    Updated: 2020/01/28 12:14:22 by hyu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf

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

INCLUDES=-I minilibx/ -I libft/
FLAG=-Wall -Werror -Wextra -g

LIBFT=-L libft -l ft
FRAMEWORK=-framework OpenGL -framework Appkit
MLX=-L ~/Desktop/minilibx_macos -l mlx

all: $(NAME)
$(NAME):
	make -C libft
	make -C minilibx
	cc $(LIBFT) $(MLX) $(FRAMEWORK) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJECTS)
	make -C libft clean
	make -C minilibx clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re:fclean all
