/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lst_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:40:30 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/16 18:20:34 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back_ps(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!(*lst))
		return (ft_lstadd_front_ps(lst, new));
	last = ft_lstlast_ps(*lst);
	last->next = new;
}

void	ft_lstadd_front_ps(t_stack **lst, t_stack *new)
{
	if (!(new))
		return ;
	new->next = *lst;
	*lst = new;
}

t_stack	*ft_lstnew_ps(int *content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!(new))
		return (0);
	new->content = content;
	new->target = new;
	new->count = 0;
	new->is_rev = 0;
	new->is_mid = 0;
	new->next = NULL;
	return (new);
}

int	ft_lstsize_ps(t_stack *lst)
{
	int		i;
	t_stack	*temp;

	temp = lst;
	i = 0;
	if (!(temp))
		return (0);
	while (temp->next)
	{
		temp = temp->next;
		i++;
	}
	return (i + 1);
}
