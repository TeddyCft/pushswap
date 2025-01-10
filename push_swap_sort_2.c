/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:53:43 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/10 20:00:37 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rot_to_max(t_stack *st, t_stack **found)
{
	int	i;

	i = 0;
	*found = get_max(st);
	while (st->next != *found && st != *found)
	{
		st = (st)->next;
		i++;
	}
	return (i);
}

int	small_sort(t_stack **st)
{
	if (stack_size(*st) > 3)
		return (0);
	if (stack_size(*st) == 3)
		sort_three(st);
	else
	{
		if ((*st)->content > (*st)->next->content)
			op_swap(st, 'a');
	}
	return (1);
}

int	rot_count(t_stack *st_a, t_stack *st_b)
{
	int	i;

	i = 0;
	while (st_b != st_a->target)
	{
		i++;
		st_b = st_b->next;
	}
	return (i);
}

/* count how many operation is needed to push any element from a to b and return
the cheapest element to push */
void	get_cheap(t_data *data, t_stack *st_a, t_stack *st_b)
{
	int	i;

	i = 0;
	while ((st_a)->next != NULL)
	{
		st_a->count = i + 1 + rot_count(st_a, st_b);
		if (!data->target_a)
			data->target_a = st_a;
		if (st_a->count < data->target_a->count)
			data->target_a = st_a;
		st_a = (st_a)->next;
	}
}

/* push the cheapest element of st a into stack b using the least
amount of operations */
void	push_cheap(t_data *data, t_stack **st_a, t_stack **st_b)
{
	while (*st_a != data->target_a && *st_b != data->target_a->target)
	{
		op_rr(st_a, st_b);
	}
	while (*st_a != data->target_a)
		op_rot(st_a, 'a');
	while (*st_b != data->target_a->target)
		op_rot(st_b, 'b');
	op_push(st_a, st_b, 'b');
	reset_targets(*st_a);
	data->target_a = 0;
}
