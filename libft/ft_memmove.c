/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:19:05 by tcoeffet          #+#    #+#             */
/*   Updated: 2024/11/18 10:44:01 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The  memmove()  function copies n bytes from memory area src to memory area
dest. The memory areas may overlap: copying takes place as though the bytes in
src are first copied into a temporary array that does not overlap src or dest,
and the bytes are then copied from the temporary array to dest. */

#include"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*source;

	i = 0;
	if (dest == 0 && src == 0)
		return (0);
	dst = (unsigned char *)dest;
	source = (unsigned char *)src;
	if (source < dst)
	{
		while (n > 0)
		{
			dst[n - 1] = source[n - 1];
			n--;
		}
		return (dest);
	}
	else
		return (ft_memcpy(dest, src, n));
}

/* int		main(int argc, const char *argv[])
{
	char	src[] = "lorem ipsum dolor sit amet";
	char	*dest;
	
	(void)argc;
	(void)argv;
	dest = src + 1;
	printf("tst rem ipssum dolor sit a\n");
	//printf("OG %s\n",(char *) memmove(src, dest, 8));
	printf("FT %s\n",(char *)ft_memmove(src, dest, 8));
	printf("dst %s\n", dest);
	printf("src %s\n", src);
	return (0);
} */