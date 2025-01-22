/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:13:07 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/22 15:55:54 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//sorts the three last elements of stack a
void	sort_three(t_stack **st)
{
	int		i;
	t_stack	*min;
	t_stack	*max;
	t_stack	*start;

	if (is_sort(*st))
		return ;
	start = *st;
	min = *st;
	max = *st;
	i = 0;
	(*st)->next->next->next = *st;
	while (i++ < 3)
	{
		if ((*st)->content[0] < min->content[0])
			min = *st;
		if ((*st)->content[0] > max->content[0])
			max = *st;
		*st = (*st)->next;
	}
	*st = start;
	start->next->next->next = NULL;
	if (max->next != min || \
		(start == max && start->next->next == min))
		op_swap(st, 'a');
}

/* push all the element of stack b into stack a */
void	push_b_to_a(t_stack **st_a, t_stack **st_b)
{
	while (*st_b)
	{
		get_all_targets(*st_b, *st_a, 'b');
		if (!(*st_b)->tar_is_rev)
		{
			while (*st_a != (*st_b)->target)
			{
				op_rot(st_a, 'a');
			}
		}
		else
		{
			while (*st_a != (*st_b)->target)
			{
				op_rev_rot(st_a, 'a');
			}
		}
		op_push(st_b, st_a, 'a');
	}
}

//count the number of elements in stack st
int	stack_size(t_stack *st)
{
	int	i;

	i = 0;
	while (st)
	{
		i++;
		st = st->next;
	}
	return (i);
}

//returns the adress of the biggest number in stack st
t_stack	*get_max(t_stack *st)
{
	int		i;
	t_stack	*start;

	start = st;
	i = 0;
	while (st)
	{
		if (*(int *)st->content > i)
			i = *(int *)st->content;
		st = st->next;
	}
	while (*(int *)start->content != i)
		start = start->next;
	return (start);
}

//returns the adress of the smallest element in stack st
t_stack	*get_min(t_stack *st)
{
	int		i;
	t_stack	*start;

	start = st;
	i = *(int *)st->content;
	while (st)
	{
		if (*(int *)st->content < i)
			i = *(int *)st->content;
		st = st->next;
	}
	while (*(int *)start->content != i)
		start = start->next;
	return (start);
}
