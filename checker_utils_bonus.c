/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:50:08 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/16 13:27:00 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	do_push(char *op, t_stack **st_a, t_stack **st_b)
{
	if (op[1] == 'a')
		op_push(st_b, st_a, 'a');
	else
		op_push(st_a, st_b, 'b');
	return (1);
}

int	do_swap(char *op, t_stack **st_a, t_stack **st_b)
{
	if (op[1] == 'a')
		op_swap(st_a, 'a');
	else
		op_swap(st_b, 'b');
	return (1);
}

int	do_rot(char *op, t_stack **st_a, t_stack **st_b)
{
	if (op[1] == 'a')
		op_rot(st_a, 'a');
	else
		op_rot(st_b, 'b');
	return (1);
}

int	do_rev_rot(char *op, t_stack **st_a, t_stack **st_b)
{
	if (op[2] == 'a')
		op_rot(st_a, 'a');
	else
		op_rot(st_b, 'b');
	return (1);
}