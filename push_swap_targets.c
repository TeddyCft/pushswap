/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_targets.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:38:09 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/22 16:03:53 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//set the targets registered in stack st to 0
void	reset_targets(t_stack *st)
{
	while (st)
	{
		st->target = 0;
		st = st->next;
	}
}

/*checks the whole stack b for the most convenient node to target 
from the first node of st_a*/
t_stack	*get_target_a(t_stack *st_a, t_stack *st_b)
{
	int		a;
	t_stack	*found;
	t_stack	*max;

	max = get_max(st_b);
	found = 0;
	a = st_a->content[0];
	while (st_b)
	{
		if (!found && a > st_b->content[0])
			found = st_b;
		else if (a > st_b->content[0] && found->content[0] < st_b->content[0])
			found = st_b;
		st_b = st_b->next;
	}
	if (!found)
		found = max;
	return (found);
}

/*checks the whole stack a for the most convenient node to target 
from the first node of st_b*/
t_stack	*get_target_b(t_stack *st_b, t_stack *st_a)
{
	int		b;
	t_stack	*found;
	t_stack	*min;

	min = get_min(st_a);
	found = 0;
	b = st_b->content[0];
	while (st_a)
	{
		if (!found && b < st_a->content[0])
			found = st_a;
		else if (b < st_a->content[0] && found->content[0] > st_a->content[0])
			found = st_a;
		st_a = st_a->next;
	}
	if (!found)
		found = min;
	return (found);
}

/*if c = 'a' seeks for the closest smaller int to st_a in st_b max if not found
  if c = 'b' seeks for the closest higher int to st_b in st_a min if not found
*/
void	get_all_targets(t_stack *st1, t_stack *st2, char c)
{
	int	i;
	int	size;

	i = 0;
	size = stack_size(st1);
	while (st1)
	{
		if (c == 'a')
			st1->target = get_target_a(st1, st2);
		else
			st1->target = get_target_b(st1, st2);
		st1->count = get_count(st1, st2, i, size - i);
		st1 = st1->next;
		i++;
	}
}
