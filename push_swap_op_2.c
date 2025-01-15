/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teddy <teddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:32:27 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/15 22:07:14 by teddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_new_last(t_stack *st, t_stack *tofind)
{
	while (st->next != tofind)
		st = st->next;
	return (st);
}

/* rotate : moves every element of the stack c upward,
the top one becomes the bottom one (back to front) */
int	op_rot(t_stack **st, char c)
{
	t_stack	*tmp;

	if (!(*st))
		return (0);
	tmp = *st;
	*st = (*st)->next;
	(*st)->prev = NULL;
	tmp->prev = ft_lstlast_ps(*st);
	ft_lstlast_ps(*st)->next = tmp;
	tmp->next = NULL;
	if (c != 'x')
		ft_printf("r%c\n", c);
	return (1);
}

/* rotates both stacks */
int	op_rr(t_stack **st1, t_stack **st2)
{
	if (op_rot(st1, 'x') && op_rot(st2, 'x'))
	{
		ft_printf("rr\n");
		return (1);
	}
	return (0);
}

/* reverse rotate : moves every element of the stack c downward,
the bottom one becomes the top one (front to back) */
int	op_rev_rot(t_stack **st, char c)
{
	t_stack	*tmp;

	if (!(*st))
		return (0);
	tmp = *st;
	*st = ft_lstlast_ps(*st);
	find_new_last(tmp, *st)->next = NULL;
	(*st)->next = tmp;
	tmp->prev = *st;
	(*st)->prev = NULL;
	if (c != 'x')
		ft_printf("rr%c\n", c);
	return (1);
}

/* reverse rotates both stacks */
int	op_rrr(t_stack **st1, t_stack **st2)
{
	op_rev_rot(st1, 'x');
	op_rev_rot(st2, 'x');
	ft_printf("rrr\n");
	return (1);
}
