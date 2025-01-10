/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:53:43 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/10 17:24:30 by tcoeffet         ###   ########.fr       */
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

int	rot_count(t_data *data, int content, t_stack *st)
{
	int		i;
	t_stack	*found;
	t_stack	*start;

	start = st;
	found = 0;
	i = 0;
	while ((st)->content[0] > content && st)
	{
		if ((st)->content[0] > content)
			found = st;
		st = (st)->next;
		i++;
	}
	if (!found)
	{
		st = start;
		i = rot_to_max(st, &found);
	}
	data->temp = found;
	return (i);
}

/* count how many operation is needed to push any element from a to b and return
the cheapest element to push */
void	get_cheap(t_data *data, t_stack *st_a, t_stack *st_b)
{
	int	i;
	int	count;

	i = 0;
	while ((st_a)->next != NULL)
	{
		count = i + 1 + rot_count(data, (st_a)->content[0], st_b);
		if (count < data->count || data->count == 0)
		{
			data->cheap = st_a;
			data->count = count;
			data->topush = data->temp;
		}
		i++;
		st_a = (st_a)->next;
	}
}

/* push the cheapest element of st a into stack b using the least
amount of operations */
void	push_cheap(t_data *data, t_stack **st_a, t_stack **st_b)
{
	while (*st_a != data->cheap && *st_b != data->topush)
	{
		op_rr(st_a, st_b);
	}
	while (*st_a != data->cheap)
		op_rot(st_a, 'a');
	while (*st_b != data->topush)
		op_rot(st_b, 'b');
	op_push(st_a, st_b, 'b');
	data->cheap = 0;
	data->temp = 0;
	data->count = 0;
	data->topush = 0;
}
