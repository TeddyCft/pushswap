/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teddy <teddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:13:35 by teddy             #+#    #+#             */
/*   Updated: 2025/01/15 22:14:16 by teddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	absol(int val)
{
	if (val < 0)
		val = -val;
	return (val);
}
