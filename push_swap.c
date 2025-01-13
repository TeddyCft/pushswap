/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:45:17 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/13 10:59:11 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks(t_stack **st_a, t_stack **st_b)
{
	t_data	*data;

	data = malloc(sizeof (t_data));
	if (!data)
		return ;
	if (small_sort(st_a))
		return ;
	op_push(st_a, st_b, 'b');
	if (!(stack_size(*st_a) == 3))
		op_push(st_a, st_b, 'b');
	// print_stacks(*st_a, *st_b);
	// ft_printf("/\\ push init /\\ \n----------\n\n");
	while (stack_size(*st_a) > 2)
	{
		get_all_targets(*st_a, *st_b, 'a');
		get_cheap(data, *st_a, *st_b);
		push_cheap(data, st_a, st_b);
		// print_stacks(*st_a, *st_b);
		// ft_printf("/\\ push cheap /\\ \n----------\n\n");
	}
	sort_three(st_a);
	// print_stacks(*st_a, *st_b);
	// ft_printf("/\\ sort three /\\ \n----------\n\n");
	push_b_to_a(st_a, st_b);
	// print_stacks(*st_a, *st_b);
	// ft_printf("/\\ push b to a /\\ \n----------\n\n");
	while (!(is_sort(*st_a)))
	{
		//print_stacks(*st_a, *st_b);
		op_rot(st_a, 'a');
	}
	return ;
	free(data);
}

/* void	sort_stacks_test(t_stack **st_a, t_stack **st_b)
{
	op_push(st_a, st_b, 'b');
	print_stacks(*st_a, *st_b);
	op_swap(st_a, 'a');
	print_stacks(*st_a, *st_b);
	op_push(st_a, st_b, 'b');
	print_stacks(*st_a, *st_b);
	op_ss(*st_a, *st_b);
	print_stacks(*st_a, *st_b);
	op_rot(st_a, 'a');
	print_stacks(*st_a, *st_b);
	op_rev_rot(st_a, 'a');
	print_stacks(*st_a, *st_b);
	return ;
} */

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
	if (error == 1)
		return (ft_lstclear_ps(&st_a, &free), ft_printf("Error\n"), 0);
	sort_stacks(&st_a, &st_b);
	//print_stacks(st_a, st_b);
	return (ft_lstclear_ps(&st_a, &free), ft_lstclear_ps(&st_b, &free), 0);
}

