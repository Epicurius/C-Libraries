/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Compares the first 'n' bytes of the block of memory pointed by 'ptr1'
 * to the first 'n' bytes pointed by 'ptr2', returning zero if they all match or
 * a value different from zero representing which is greater if they do not.
 */
int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	size_t			x;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)ptr1;
	p2 = (unsigned char *)ptr2;
	x = 0;
	while (n--) {
		if (p1[x] != p2[x])
			return (p1[x] - p2[x]);
		x++;
	}
	return 0;
}
