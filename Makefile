#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: loram <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 17:36:15 by loram             #+#    #+#              #
#    Updated: 2019/11/05 17:38:18 by loram            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRC =        srcs/check_input.c\
              srcs/ft_cellnew.c\
              srcs/get_next_line.c\
              srcs/main.c\
              srcs/tetrimino.c\
              srcs/ft_freecell.c\
              srcs/ft_freehead.c\
              srcs/ft_find_first_cell.c\
              srcs/ft_alg.c\
              srcs/ft_exclude_row.c\
              srcs/ft_get_hd_up.c\
              srcs/ft_excl_all_h_and_r.c\
              srcs/ft_inc_all_h_and_r.c\
              srcs/ft_include_row.c\
              srcs/inputting.c\
              srcs/ft_input.c\
              srcs/ft_create_header.c\
              srcs/ft_free_all.c\
              srcs/ft_check_heads_tetr_inc.c\
              srcs/ft_freelist.c\
              srcs/ft_print.c\
              srcs/make_list.c\
              srcs/dim_make.c

OBJ = $(SRC:.c=.o)

INC = -I includes

LIBFT =	srcs/libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) ./srcs/libft/*
		@$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ): %.o: %.c
		@$(CC) $(FLAGS) -o $@ -c $<

$(LIBFT):
		@make -C ./srcs/libft/

clean:
		@rm -f $(OBJ)
			@make clean -C ./srcs/libft/

fclean: clean
		@rm -f $(NAME)
			@make fclean -C ./srcs/libft/

re: fclean all

.PHONY : all, re, clean, fclean
