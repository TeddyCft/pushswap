# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teddy <teddy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 16:29:48 by tcoeffet          #+#    #+#              #
#    Updated: 2025/01/15 22:20:23 by teddy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		push_swap

LIBFT =		./libft/libft.a

SOURCES = 	$(LIBFT)\
			push_swap_lst_1.c\
			push_swap_lst_2.c\
			push_swap.c\
			push_swap_count.c\
			push_swap_parsing.c\
			push_swap_utils.c\
			push_swap_utils_2.c\
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

ARG = "6 21 1 27 4 7 12 8 14 9 30 20 15 24 18 26 28 29 5 25 2 3 13 10 16 11 22 23 19 17"

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
