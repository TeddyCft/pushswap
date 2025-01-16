/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:54:12 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/16 18:08:43 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# ifndef IS_CHECK
#  define IS_CHECK 0
# endif

typedef struct s_stack
{
	int				*content;
	int				is_rev;
	int				is_mid;
	int				count;
	struct s_stack	*target;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct data
{
	int		count;
	t_stack	*temp;
	t_stack	*cheap;
	t_stack	*max;
	t_stack	*min;
}					t_data;

//push_swap

void	sort_stacks(t_stack **st_a, t_stack **st_b);

//error_check

int		check_int(char *str, int i);
int		error_check(int argc, char **argv);

//check_error_utils

int		ft_is_empty(char *str);
int		ft_is_sign(char c);
int		is_int(char *str, char end);
int		ft_is_set(char *str);

//lst_1

void	ft_lstadd_back_ps(t_stack **lst, t_stack *new);
void	ft_lstadd_front_ps(t_stack **lst, t_stack *new);
int		ft_lstsize_ps(t_stack *lst);
t_stack	*ft_lstnew_ps(int *content);

//lst_2

void	ft_lstclear_ps(t_stack **lst, void (*del)(void *));
void	ft_lstdelone_ps(t_stack *lst, void (*del)(void *));
void	ft_lstiter_ps(t_stack *lst, void (*f)(void *));
t_stack	*ft_lstmap_ps(t_stack *lst, void *(*f)(void *), void(*del)(void *));
t_stack	*ft_lstlast_ps(t_stack *lst);

//count

int	get_k(t_stack *st, t_stack *target);
int	get_j(t_stack *st, t_stack *target);
int	get_count(t_stack *st, t_stack *target, int i);

//op_1

int		op_swap(t_stack **st, char c);
int		op_ss(t_stack **st1, t_stack **st2);
int		op_push(t_stack **from, t_stack **to, char c);

//op_2

int		op_rot(t_stack **st, char c);
int		op_rr(t_stack **st1, t_stack **st2);
int		op_rev_rot(t_stack **st, char c);
int		op_rrr(t_stack **st1, t_stack **st2);

//parsing

void	pars_init(int argc, char **argv, t_stack **s_a, int *error);

//sort_1

void	sort_three(t_stack **st);
void	push_b_to_a(t_stack **st_a, t_stack **st_b);
int		stack_size(t_stack *st);
t_stack	*get_max(t_stack *st);
t_stack	*get_min(t_stack *st);

//sort_2

void	push_cheap(t_data *data, t_stack **st_a, t_stack **st_b);
void	get_cheap(t_data *data, t_stack *st_a);
int		small_sort(t_stack **st);
void	roll_a(t_data *data, t_stack **st_a);
void	roll_b(t_data *data, t_stack **st_b);

//targets

void	reset_targets(t_stack *st);
void	get_all_targets(t_stack *st1, t_stack *st2, char c);

//utils

void	ft_clear_split(char **split);
int		absol(int val);
int		is_sort(t_stack *st);
int		is_max(t_stack *st);
int		ft_min(int a, int b);
void	reset_stack(t_stack *st);
int		ft_max(int a, int b);

//testing

void	rev_print_stacks(t_stack *st_a, t_stack *st_b);
void	rev_print_stack(t_stack *st, char c);
void	print_stacks(t_stack *st_a, t_stack *st_b);
void	print_stack(t_stack *st, char c);
void	print_data(t_data *data);

#endif