/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:09:59 by teddy             #+#    #+#             */
/*   Updated: 2025/01/22 16:21:21 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bwd(t_stack *st, t_stack *target)
{
	t_stack	*start;
	int		bwd;

	start = st;
	bwd = 1;
	st = ft_lstlast_ps(st);
	while (st != target)
	{
		bwd++;
		st = st->prev;
	}
	st = start;
	return (bwd);
}

int	get_fwd(t_stack *st, t_stack *target)
{
	t_stack	*start;
	int		fwd;

	start = st;
	fwd = 0;
	while (st != target)
	{
		fwd++;
		st = st->next;
	}
	st = start;
	return (fwd);
}

/*count the smallest number of actions needed to reach the target from the node
*st in stack st. returns a negative value if the actions should be reverted*/
int	get_count(t_stack *st1, t_stack *st2, int i, int rev_i)
{
	int	fwd;
	int	bwd;
	int	count;

	fwd = get_fwd(st2, st1->target);
	bwd = get_bwd(st2, st1->target);
	count = ft_max(fwd - i, 0) + i;
	// ft_printf("#######\n0 count = %d\n", count);
	if (count > fwd + rev_i)
	{
		st1->is_rev = 1;
		count = fwd + rev_i;
		// ft_printf("1 count = %d\n", count);
	}
	if (count > ft_max(bwd - rev_i, 0) + rev_i)
	{
		st1->is_rev = 1;
		st1->tar_is_rev = 1;
		count = ft_max(bwd - rev_i, 0) + rev_i;
		// ft_printf("2 count = %d\n", count);
	}
	if (count > bwd + i)
	{
		st1->is_rev = 0;
		st1->tar_is_rev = 1;
		count = bwd + i;
		// ft_printf("3 count = %d\n", count);
	}
	// ft_printf("########\n");
	return (count);
}
