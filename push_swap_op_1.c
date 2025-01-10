/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:15:57 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/09 13:35:59 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* swap : swaps the 2 firsts elements on top of stack c */
int	op_swap(t_stack **st, char c)
{
	int	*temp;

	if (!st || !(*st)->next)
		return (0);
	temp = (*st)->next->content;
	(*st)->next->content = (*st)->content;
	(*st)->content = temp;
	if (c != 'x')
		ft_printf("s%c\n", c);
	return (1);
}

/* swaps both stacks */
int	op_ss(t_stack *st_a, t_stack *st_b)
{
	if (op_swap(&st_a, 'x') && op_swap(&st_b, 'x'))
	{
		ft_printf("ss\n");
		return (1);
	}
	return (0);
}

/* push : puts the first element of stack 'from' on top of stack 'to'*/
int	op_push(t_stack **from, t_stack **to, char c)
{
 	t_stack	*tmp;

	if (!(*from))
		return (0);
	tmp = (*from)->next;
	(*from)->next = *to;
	*to = *from;
	*from = tmp;
	ft_printf("p%c\n", c);
	return (1);
}
