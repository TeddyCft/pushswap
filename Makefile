# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 16:29:48 by tcoeffet          #+#    #+#              #
#    Updated: 2025/01/16 14:41:54 by tcoeffet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		push_swap

BONUS = 	checker

LIBFT =		./libft/libft.a

MAIN =		push_swap.c\

MAINOBJ = 	$(MAIN:.c=.o)

SOURCES = 	$(LIBFT)\
			push_swap_lst_1.c\
			push_swap_lst_2.c\
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

MAIN_BONUS = checker_bonus.c\

MAINOBJBONUS = 	$(MAIN_BONUS:.c=.o)

SRC_BONUS =	checker_bonus.c\
			checker_utils_bonus.c\

OBJ = 		$(SOURCES:.c=.o)

OBJBONUS = 	$(SRC_BONUS:.c=.o)

HEADERS =	./

FLAGS = 	-Wall -Werror -Wextra

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

$(NAME) : 	$(LIBFT) $(MAIN) $(OBJ)
	$(CC) $(FLAGS) -g $(MAIN) $(OBJ) $(LIBFT) -o $(NAME)

bonus :		$(BONUS)
		make all
		$(CC) $(FLAGS) -DIS_CHECK=1 -g  $(MAIN_BONUS) $(OBJ) $(OBJBONUS) $(LIBFT) -o $(BONUS)
$(BONUS) : $(LIBFT) $(MAIN_BONUS) $(OBJBONUS)

%.o : %.c
	$(CC) $(FLAGS) -c -g $< -o $@

clean : 
	rm -f $(OBJ) $(OBJBONUS) $(MAINOBJ) $(MAINOBJBONUS)
fclean : clean
	rm -f $(NAME) $(LIBFT) $(BONUS)
	make -C ./libft fclean
re : fclean all
