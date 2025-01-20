/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teddy <teddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:40:15 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/20 18:29:59 by teddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	do_op(char *op, t_stack **st_a, t_stack **st_b)
{
	if (!ft_strncmp("pa", op, 2) || !ft_strncmp("pb", op, 2))
		return (do_push(op, st_a, st_b));
	if (!ft_strncmp("sa", op, 2) || !ft_strncmp("sb", op, 2))
		return (do_swap(op, st_a, st_b));
	if (!ft_strncmp("ss", op, 2))
		return (op_ss(st_a, st_b));
	if (!ft_strncmp("ra", op, 2) || !ft_strncmp("rb", op, 2))
		return (do_rot(op, st_a, st_b));
	if (!ft_strncmp("rra", op, 3) || !ft_strncmp("rrb", op, 3))
		return (do_rev_rot(op, st_a, st_b));
	if (ft_strlen(op) == 3 && !ft_strncmp("rrr", op, 3))
		return (op_rrr(st_a, st_b));
	if (ft_strlen(op) == 2 && !ft_strncmp("rr", op, 3))
		return (op_rr(st_a, st_b));
	return (0);
}

int	checker(t_stack **st_a, t_stack **st_b, int *error)
{
	char	*op;

	op = get_next_line(0);
	while (op)
	{
		if (!do_op(op, st_a, st_b))
		{
			*error = 1;
			return (free(op), 0);
		}
		free(op);
		op = get_next_line(0);
	}
	free(op);
	if (is_sort(*st_a))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*st_a;
	t_stack	*st_b;
	int		error;

	error = 0;
	st_a = 0;
	st_b = 0;
	if (!error_check(argc, argv))
		return (ft_printf("Error\n"), 0);
	pars_init(argc, argv, &st_a, &error);
	if (checker(&st_a, &st_b, &error))
		return (ft_lstclear_ps(&st_a, &free), ft_printf("OK\n"), 0);
	if (error == 1)
		return (ft_lstclear_ps(&st_a, &free), ft_printf("Error\n"), 0);
	return (ft_lstclear_ps(&st_a, &free), ft_printf("KO\n"), 0);
}
