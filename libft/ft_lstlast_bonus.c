/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:40:34 by tcoeffet          #+#    #+#             */
/*   Updated: 2024/11/18 10:40:21 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Renvoie le dernier élément de la liste. */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	if (!lst)
		return (NULL);
	while (temp->next)
			temp = temp->next;
	return (temp);
}
