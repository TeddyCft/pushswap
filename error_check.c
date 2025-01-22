/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:32:53 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/22 17:06:33 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*check_int verifie que la string donnee est bien entre int min et int max*/

int	check_int(char *str, int i)
{
	int	p;
	int	m;

	p = 0;
	m = 0;
	if (str[0] == '-')
		m = 1;
	if (str[0] == '+')
		p = 1;
	if (i > 11 || ((i == 11) && (p != 1 && m != 1)))
		return (0);
	if (i == 11)
	{
		if (m == 1 && (ft_strncmp(str, "-2147483648", i) > 0))
			return (0);
		if (p == 1 && (ft_strncmp(str, "+2147483647", i) > 0))
			return (0);
	}
	if (i == 10 && m == 0 && str[0] != '-' && \
	ft_strncmp(str, "2147483647", i) > 0)
		return (0);
	return (1);
}

int	is_list(char *str)
{
	int	i;
	int	space;

	space = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ' && str[i])
		{
			i++;
			space = 1;
		}
		if (ft_isdigit(str[i]) || ft_is_sign(str[i]))
		{
			if (!is_int(str + i, ' '))
				return (0);
			while (str[i] && (ft_isdigit(str[i]) || ft_is_sign(str[i])))
				i++;
		}
		if (str[i] && str[i] != ' ')
			i++;
	}
	if (space == 1)
		return (1);
	return (0);
}

int	error_check(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc <= 1 || !argv[1])
		return (0);
	if (argc == 2)
	{
		if (ft_is_empty(argv[1]) || !ft_is_set(argv[1]))
			return (0);
		if (!is_list(argv[1]))
			if (!is_int(argv[1], '\0'))
				return (0);
		return (1);
	}
	while (i < argc)
	{
		if (!is_int(argv[i], '\0'))
			return (0);
		i++;
	}
	return (1);
}
