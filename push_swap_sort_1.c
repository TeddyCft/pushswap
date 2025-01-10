/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:13:07 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/10 20:05:16 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//sorts the three last elements of stack a
void	sort_three(t_stack **st)
{
	int	top;
	int	mid;
	int	bot;

	top = *(int *)(*st)->content;
	mid = *(int *)(*st)->next->content;
	bot = *(int *)(*st)->next->next->content;
	if (top > mid && mid > bot)
	{
		op_swap(st, 'a');
		op_rev_rot(st, 'a');
	}
	else if (mid > top && mid > bot && top < bot)
	{
		op_swap(st, 'a');
		op_rot(st, 'a');
	}
	else if (top > mid && mid < bot)
		op_swap(st, 'a');
	else if (top < mid && mid > bot)
		op_rev_rot(st, 'a');
	else if (top > mid && mid < bot)
		op_rot(st, 'a');
}

/* push all the element of stack b into stack a */
void	push_b_to_a(t_stack **st_a, t_stack **st_b)
{
	while (*st_b)
	{
		get_all_targets(*st_b, *st_a, 'b');
		while (*st_a != (*st_b)->target)
		{
			op_rot(st_a, 'a');
		}
		op_push(st_b, st_a, 'a');
	}
}

int	stack_size(t_stack *st)
{
	int	i;

	i = 0;
	while (st->next != NULL)
	{
		i++;
		st = st->next;
	}
	return (i);
}

t_stack	*get_max(t_stack *st)
{
	int		i;
	t_stack	*start;

	start = st;
	i = 0;
	while (st->next)
	{
		if (*(int *)st->content > i)
			i = *(int *)st->content;
		st = st->next;
	}
	while (*(int *)start->content != i)
		start = start->next;
	return (start);
}

t_stack	*get_min(t_stack *st)
{
	int		i;
	t_stack	*start;

	start = st;
	i = *(int *)st->content;
	while (st->next)
	{
		if (*(int *)st->content < i)
			i = *(int *)st->content;
		st = st->next;
	}
	while (*(int *)start->content != i)
		start = start->next;
	return (start);
}

