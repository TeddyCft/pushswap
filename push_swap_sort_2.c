/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:53:43 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/22 15:46:31 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sorts the stack if the number of node is 3 or less
int	small_sort(t_stack **st)
{
	if (stack_size(*st) > 3)
		return (0);
	if (stack_size(*st) == 3)
	{
		sort_three(st);
		if (!is_sort(*st) && is_max(*st))
			op_rot(st, 'a');
		else if (!is_sort(*st))
			op_rev_rot(st, 'a');
	}
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
		if (cheap->count > st_a->count)
			cheap = st_a;
		st_a = (st_a)->next;
	}
	data->cheap = cheap;
}

/* push the cheapest element of st a into stack b using the least
amount of operations */
void	push_cheap(t_data *data, t_stack **st_a, t_stack **st_b)
{
	if (!data->cheap->tar_is_rev && !data->cheap->is_rev)
	{
		while (*st_a != data->cheap && *st_b != data->cheap->target)
			op_rr(st_a, st_b);
	}
	if (data->cheap->tar_is_rev && data->cheap->is_rev)
	{
		while (*st_a != data->cheap && *st_b != data->cheap->target)
			op_rrr(st_a, st_b);
	}
	roll_a(data, st_a);
	roll_b(data, st_b);
	op_push(st_a, st_b, 'b');
}

void	roll_a(t_data *data, t_stack **st_a)
{
	while (*st_a != data->cheap)
	{
		if (data->cheap->is_rev)
			op_rev_rot(st_a, 'a');
		else
			op_rot(st_a, 'a');
	}
}

void	roll_b(t_data *data, t_stack **st_b)
{
	while (*st_b != data->cheap->target)
	{
		if (data->cheap->tar_is_rev)
			op_rev_rot(st_b, 'b');
		else
			op_rot(st_b, 'b');
	}
}
