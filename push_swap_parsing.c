/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:41:30 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/10 18:53:51 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_struct(int argc, char **list, t_stack **st_a)
{
	t_stack	*new;
	int		*content;
	int		i;

	i = 0;
	while (list[i] && (i < argc || argc == 2))
	{
		content = ft_calloc(1, sizeof (int));
		if (!content)
		{
			ft_clear_split(list);
			return (ft_lstclear_ps(st_a, &free), 0);
		}
		*content = ft_atoi(list[i]);
		new = ft_lstnew_ps(content);
		new->target = new;
		new->count = 0;
		ft_lstadd_back_ps(st_a, new);
		i++;
	}
	return (1);
}

void	pars_init(int argc, char **argv, t_stack **st_a, int *error)
{
	char	**list;

	*error = 1;
	list = 0;
	if (argc == 2)
	{
		list = ft_split(argv[1], ' ');
		if (!list)
			return ;
	}
	else
		list = &argv[1];
	if (!init_struct(argc, list, st_a))
		return ;
	*error = 0;
	if (argc == 2)
		ft_clear_split(list);
	return ;
}

void	print_stacks(t_stack *st_a, t_stack *st_b)
{
	ft_printf("\n");
	print_stack(st_a, 'a');
	print_stack(st_b, 'b');
	ft_printf("\n");
}

void	print_stack(t_stack *st, char c)
{
	ft_printf("--STACK-[%c]--\n", c - 32);
	while (st)
	{
		ft_printf("%d\n", *(int *)st->content);
		st = st->next;
	}
	ft_printf("---------------\n");
}
