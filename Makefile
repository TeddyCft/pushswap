# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 16:29:48 by tcoeffet          #+#    #+#              #
#    Updated: 2025/01/22 13:15:47 by tcoeffet         ###   ########.fr        #
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

SRC_BONUS =	checker_utils_bonus.c\

OBJ = 		$(SOURCES:.c=.o)

OBJBONUS = 	$(SRC_BONUS:.c=.o)

HEADERS =	./

FLAGS = 	-Wall -Werror -Wextra

CC = 		cc

MAKE_LIB = 	make -C ./libft all

TEST = 		a.out

ARG = "3 2 10 11 12 17 7 5 19 20 6 15 18 14 9 16 1 13 8 4"

all :		$(NAME)


test :		$(TEST)
				./a.out $(ARG) > result.txt

$(TEST) : 	$(OBJ) $(MAINOBJ)
	$(CC) $(FLAGS) -I$(HEADERS) -g $(MAINOBJ) $(OBJ) $(LIBFT)

$(LIBFT) :
	$(MAKE_LIB)

$(NAME) : 	$(LIBFT) $(MAINOBJ) $(OBJ)
	$(CC) $(FLAGS) -g $(MAINOBJ) $(OBJ) $(LIBFT) -o $(NAME)

bonus :	$(BONUS)
		$(CC) $(FLAGS) -g  $(MAINOBJBONUS) $(OBJ) $(OBJBONUS) $(LIBFT) -o $(BONUS)
		make re
$(BONUS) : $(LIBFT) $(MAINOBJBONUS) $(OBJ) $(OBJBONUS)

ifneq ($(filter bonus, $(MAKECMDGOALS)),)
FLAGS += -DIS_CHECK=1
endif

$(OBJBONUS) : 
%.o : %.c
	$(CC) $(FLAGS) -c -g $< -o $@

clean : 
	rm -f $(MAINOBJ)
fclean : clean
	rm -f $(NAME) $(LIBFT) $(OBJ)
	make -C ./libft fclean
re : fclean all

cleanbonus : 
	rm -f $(OBJBONUS) $(MAINOBJ) $(MAINOBJBONUS)

fcleanbonus :	cleanbonus
	rm -f $(NAME) $(BONUS) $(LIBFT) $(OBJ) $(OBJBONUS)
	make -C ./libft fclean

rebonus : fcleanbonus all
