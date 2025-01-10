/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:27:57 by tcoeffet          #+#    #+#             */
/*   Updated: 2024/11/18 10:32:59 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* checks for an alphanumeric character;
it is equivalent to (isalpha(c) || isdigit(c)). */

#include"libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || \
	(c >= '0' && c <= '9'))
		return (1);
	return (0);
}
/*
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int	main(int argc, char **argv)
{
	(void) argc;
	printf("%d\n%d", isalnum(atoi(argv[1])), ft_isalnum(atoi(argv[1])));
}
*/