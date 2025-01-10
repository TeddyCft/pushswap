/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:46:09 by tcoeffet          #+#    #+#             */
/*   Updated: 2024/12/17 15:04:50 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_empty(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

int	ft_is_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	is_int(char *str, char end)
{
	int		i;

	i = 0;
	if (ft_is_sign(str[0]))
		i++;
	while (str[i] != end && str[i] != '\0')
	{
		if (!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	if (i >= 10)
		return (check_int(str, i));
	return (1);
}

int	ft_is_set(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_is_sign(str[i]) && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
