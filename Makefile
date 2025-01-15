# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teddy <teddy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 16:29:48 by tcoeffet          #+#    #+#              #
#    Updated: 2025/01/15 14:09:33 by teddy            ###   ########.fr        #
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

ARG = "26 22 33 3 20 6 14 34 27 41 35 17 39 4 28 11 24 10 48 15 47 32 25 13 44 46 8 49 2 37 18 7 50 19 31 40 43 29 36 1 30 38 9 16 42 21 5 45 23 12"

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
