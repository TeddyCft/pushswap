# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teddy <teddy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 16:29:48 by tcoeffet          #+#    #+#              #
#    Updated: 2025/01/15 17:57:39 by teddy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		push_swap

LIBFT =		./libft/libft.a

SOURCES = 	$(LIBFT)\
			push_swap_lst_1.c\
			push_swap_lst_2.c\
			push_swap.c\
			push_swap_parsing.c\
			push_swap_utils.c\
			push_swap_op_1.c\
			push_swap_op_2.c\
			push_swap_sort_1.c\
			push_swap_sort_2.c\
			push_swap_targets.c\
			error_check.c\
			error_check_utils.c\
			
OBJ = 		$(SOURCES:.c=.o)

HEADERS =	push_swap.h

FLAGS = 	-Wall -Werror -Wextra -Wno-unused-but-set-variable

CC = 		cc

MAKE_LIB = 	make -C ./libft all

TEST = 		a.out

ARG = "3 10 13 2 7 12 14 9 6 5 11 1 4 15 8 "

all :		$(NAME)

test :		$(TEST)
				./a.out $(ARG) > result.txt
				
$(TEST) : 	$(OBJ)
	$(CC) $(FLAGS) -I$(HEADERS) -g $(OBJ) $(LIBFT)

$(LIBFT) :
	$(MAKE_LIB)

$(NAME) : 	$(LIBFT) $(OBJ)
	$(CC) $(FLAGS) -I$(HEADERS) -g $(OBJ) $(LIBFT) -o $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c -I$(HEADERS) -g $< -o $@

clean : 
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME) $(LIBFT)
	make -C ./libft fclean
re : fclean all
