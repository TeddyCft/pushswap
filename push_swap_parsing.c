/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:41:30 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/25 13:15:38 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//create the stack a using the number list created by pars_init
int	init_struct(int argc, char **list, t_stack **st_a)
{
	t_stack	*new;
	t_stack	*prev;
	int		*content;
	int		i;

	prev = 0;
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
		new->prev = prev;
		ft_lstadd_back_ps(st_a, new);
		prev = new;
		i++;
	}
	return (1);
}

int	is_double(char **list)
{
	int	i;
	int	j;

	i = 0;
	while (list[i + 1])
	{
		j = 1;
		while (list[i + j])
		{
			if (!ft_strncmp(list[i + j], list[i], \
				ft_max(ft_strlen(list[i]), ft_strlen(list[i + j]))))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

//takes every argument and puts it into a double array, if argc == 2, uses split
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
	if (!init_struct(argc, list, st_a) || is_double(list))
		return ;
	*error = 0;
	if (argc == 2)
	{
		ft_clear_split(list);
		free(list);
	}
	return ;
}
/* 
//////// TESTING /////////
//testing function, prints both stacks
void	print_stacks(t_stack *st_a, t_stack *st_b)
{
	ft_printf("\n");
	print_stack(st_a, 'a');
	print_stack(st_b, 'b');
	ft_printf("\n");
}

//testing function, prints the stack c
void	print_stack(t_stack *st, char c)
{
	ft_printf("---STACK-[%c]---\n", c - 32);
	while (st)
	{
		ft_printf("%d, tar = %d is_rev = %d count = %d\n", st->content[0] \
		, st->target->content[0], st->is_rev, st->count);
		st = st->next;
	}
	ft_printf("---------------\n");
}

//testing function, prints both stacks in reverse order
void	rev_print_stacks(t_stack *st_a, t_stack *st_b)
{
	ft_printf("\n");
	rev_print_stack(st_a, 'a');
	rev_print_stack(st_b, 'b');
	ft_printf("\n");
}

//testing function, prints the stack c in reverse order
void	rev_print_stack(t_stack *st, char c)
{
	st = ft_lstlast_ps(st);
	ft_printf("--rSTACK-[%c]---\n", c - 32);
	while (st)
	{
		ft_printf("%d\n", *(int *)st->content);
		st = st->prev;
	}
	ft_printf("---------------\n");
}

void	print_data(t_data *data)
{
	ft_printf("cheap = %d\n", data->cheap);
	ft_printf("count = %d\n", data->count);
	ft_printf("max = %p\n", data->max);
	ft_printf("temp = %p\n", data->temp);
}
 */