/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:09:59 by teddy             #+#    #+#             */
/*   Updated: 2025/01/16 18:17:25 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_k(t_stack *st, t_stack *target)
{
	t_stack	*start;
	int		k;

	start = st;
	k = 1;
	st = ft_lstlast_ps(st);
	while (st != target)
	{
		k++;
		st = st->prev;
	}
	st = start;
	return (k);
}

int	get_j(t_stack *st, t_stack *target)
{
	t_stack	*start;
	int		j;

	start = st;
	j = 0;
	while (st != target)
	{
		j++;
		st = st->next;
	}
	st = start;
	return (j);
}

/*count the smallest number of actions needed to reach the target from the node
*st in stack st. returns a negative value if the actions should be reverted*/
int	get_count(t_stack *st, t_stack *target, int i)
{
	int		j;
	int		k;

	j = get_j(st, target);
	k = get_k(st, target);
	if (i > 0)
	{
		j = ft_max(j - i, 0);
		k = k + i;
	}
	else if (i < 0)
	{
		k = ft_max((k - absol(i)), 0);
		j = j + absol(i);
	}
	i = absol(i);
	k = -k;
	if (j < (absol(k)))
		return (j + i + 1);
	return (k - i - 1);
}
