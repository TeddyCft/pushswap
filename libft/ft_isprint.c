/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:40:15 by tcoeffet          #+#    #+#             */
/*   Updated: 2024/11/18 10:34:58 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*checks for any printable character including space.*/

#include"libft.h"

int	ft_isprint(int c)
{
	if ((c >= ' ' && c <= '~'))
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
	printf("%d\n%d", isprint(atoi(argv[1])), ft_isprint(atoi(argv[1])));
}
*/