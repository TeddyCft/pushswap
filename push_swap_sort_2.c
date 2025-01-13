/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:53:43 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/13 19:08:08 by tcoeffet         ###   ########.fr       */
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

/* count how many operation is needed to push any element from a to b and return
the cheapest element to push */
void	get_cheap(t_data *data, t_stack *st_a)
{
	t_stack	*cheap;

	cheap = st_a;
	while (st_a)
	{
		ft_printf("sta = %d count = %d\n", st_a->content[0], st_a->count);
		ft_printf("cheap = %d count = %d\n", cheap->content[0], cheap->count);
		if (absol(cheap->count) > absol(st_a->count))
			cheap = st_a;
		st_a = (st_a)->next;
	}
	data->cheap = cheap;
}

/* push the cheapest element of st a into stack b using the least
amount of operations */
void	push_cheap(t_data *data, t_stack **st_a, t_stack **st_b)
{
	if (data->cheap > 0)
	{
		if (data->cheap->is_rev == 0)
		{
			while (*st_a != data->cheap && *st_b != data->cheap->target)
				op_rr(st_a, st_b);
		}
		while (*st_a != data->cheap)
			op_rot(st_a, 'a');
		while (*st_b != data->cheap->target)
			op_rot(st_b, 'b');
	}
	else
	{
		if (data->cheap->is_rev == 1)
		{
			while (*st_a != data->cheap && *st_b != data->cheap->target)
				op_rrr(st_a, st_b);
		}
		while (*st_a != data->cheap)
			op_rev_rot(st_a, 'a');
		while (*st_b != data->cheap->target)
			op_rev_rot(st_b, 'b');
	}
	op_push(st_a, st_b, 'b');
}
