/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:27:38 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/10 20:29:11 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(t_stack *st)
{
	while (st->next != NULL)
	{
		if (st->next->content[0] < st->content[0])
			return (0);
		st = st->next;
	}
	return (1);
}

int	is_max(t_stack *st)
{
	int	current;

	current = st->content[0];
	while (st)
	{
		if (st->content[0] > current)
			return (0);
		if (st->next == NULL)
			return (1);
		st = st->next;
	}
	return (1);
}

void	ft_clear_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
}

void	print_data(t_data *data)
{
	ft_printf("target = %d\n", data->target_a);
	ft_printf("count = %d\n", data->count);
	ft_printf("max = %p\n", data->max);
	ft_printf("temp = %p\n", data->temp);
	ft_printf("topush = %p\n----------\n", data->topush);
}
