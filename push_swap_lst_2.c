/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lst_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:46:42 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/10 13:14:39 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear_ps(t_stack **lst, void (*del)(void *))
{
	t_stack	*tempnext;

	tempnext = 0;
	if (!(lst) || (!(del)))
		return ;
	while (*lst && lst)
	{
		tempnext = (*lst)->next;
		ft_lstdelone_ps(*lst, del);
		*lst = tempnext;
	}
}

void	ft_lstdelone_ps(t_stack *lst, void (*del)(void *))
{
	if (!(lst) || (!(del)))
		return ;
	del(lst->content);
	free(lst);
}

void	ft_lstiter_ps(t_stack *lst, void (*f)(void *))
{
	if (!(lst) || (!(f)))
		return ;
	while (lst->next)
	{
		f(lst->content);
		lst = lst->next;
	}
	f(lst->content);
}

t_stack	*ft_lstlast_ps(t_stack *lst)
{
	t_stack	*temp;

	temp = lst;
	if (!lst)
		return (NULL);
	while (temp->next)
			temp = temp->next;
	return (temp);
}

t_stack	*ft_lstmap_ps(t_stack *lst, void *(*f)(void *), void(*del)(void *))
{
	t_stack	*newlst;
	t_stack	*elem;
	void	*temp;

	newlst = 0;
	while (lst)
	{
		temp = f(lst->content);
		elem = ft_lstnew_ps(temp);
		if (!(elem))
		{
			del(temp);
			ft_lstclear_ps(&newlst, del);
			return (0);
		}
		ft_lstadd_back_ps(&newlst, elem);
		lst = lst->next;
	}
	return (newlst);
}
