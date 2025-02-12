/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:45:17 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/25 18:52:49 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
push 2 from st_a to st_b then sort every element of st_a on top of st_b by
chosing the cheapest move to make until st_a size is 3. finaly pushes every
elements of st_b to st_a making sure st_a's top element is right.
*/
void	last_roll(t_stack **st)
{
	t_stack	*start;
	t_stack	*max;
	int		i;
	int		j;

	i = 1;
	j = 2;
	start = *st;
	max = get_max(*st);
	while (*st != max && i++)
		*st = (*st)->next;
	*st = ft_lstlast_ps(start);
	while (*st != max && j++)
		*st = (*st)->prev;
	*st = start;
	while (!is_sort(*st))
	{
		if (j > i)
			op_rot(st, 'a');
		else
			op_rev_rot(st, 'a');
	}
}

void	fill_b(t_data *data, t_stack **st_a, t_stack **st_b)
{
	int	size;

	size = stack_size(*st_a);
	while (size > 3)
	{
		get_all_targets(*st_a, *st_b, 'a');
		get_cheap(data, *st_a);
		push_cheap(data, st_a, st_b);
		reset_stack(*st_a);
		size--;
	}
}

void	sort_stacks(t_stack **st_a, t_stack **st_b)
{
	t_data	*data;

	data = malloc(sizeof (t_data));
	if (!data)
		return ;
	if (small_sort(data, st_a))
		return ;
	op_push(st_a, st_b, 'b');
	if (!(stack_size(*st_a) == 3))
		op_push(st_a, st_b, 'b');
	fill_b(data, st_a, st_b);
	sort_three(st_a);
	push_b_to_a(st_a, st_b);
	last_roll(st_a);
	free(data);
}

int	main(int argc, char **argv)
{
	t_stack	*st_a;
	t_stack	*st_b;
	int		error;

	error = 0;
	st_a = 0;
	st_b = 0;
	if (argc <= 1 || !argv[1])
		return (0);
	if (!error_check(argc, argv))
		return (write(2, "Error\n", 6));
	pars_init(argc, argv, &st_a, &error);
	if (error == 1)
		return (ft_lstclear_ps(&st_a, &free), write(2, "Error\n", 6));
	sort_stacks(&st_a, &st_b);
	return (ft_lstclear_ps(&st_a, &free), ft_lstclear_ps(&st_b, &free), 0);
}
