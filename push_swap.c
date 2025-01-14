/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:45:17 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/14 21:10:18 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
push 2 from st_a to st_b then sort every element of st_a on top of st_b by
chosing the cheapest move to make until st_a size is 3. finaly pushes every
elements of st_b to st_a making sure st_a's top element is right.
*/
void	sort_stacks(t_stack **st_a, t_stack **st_b)
{
	t_data	*data;
	int		cheap;

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
	while (stack_size(*st_a) > 3)
	{
		get_all_targets(*st_a, *st_b, 'a');
		get_cheap(data, *st_a);
		cheap = data->cheap->content[0]; /**/
		// ft_printf("\n_________\ncheap = %d count = %d\n", *(int *)data->cheap->content, data->cheap->count);
		// print_stacks(*st_a, *st_b);
		// ft_printf("/\\ push cheap /\\ \n----------\n\n");
		push_cheap(data, st_a, st_b);
		reset_stack(*st_a);
	}
	sort_three(st_a);
	// printf("/\\ sort three /\\ \n----------\n\n");
	// print_stacks(*st_a, *st_b);
	// ft_printf(" \n----------\n\\/ push b to a \\/\n\n");
	push_b_to_a(st_a, st_b);
	// print_stacks(*st_a, *st_b);
	while (!(is_sort(*st_a)))
	{
		op_rot(st_a, 'a');
	}
	// print_stacks(*st_a, *st_b);
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
	// print_stacks(st_a, st_b);
	// rev_print_stacks(st_a, st_b);
	return (ft_lstclear_ps(&st_a, &free), ft_lstclear_ps(&st_b, &free), 0);
}
