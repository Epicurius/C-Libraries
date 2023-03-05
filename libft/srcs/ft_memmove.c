/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Copies 'n' bytes from 'src' to 'dest', while avoiding memory overlap.
 */
void *ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	char	*d;
	char	*s;

	s = (char *)src;
	d = (char *)dest;
	if (s == d || n == 0)
		return dest;

	if (d > s && d - s < (int)n) {
		i = n - 1;
		while (i >= 0) {
			d[i] = s[i];
			i--;
		}

		return dest;
	}

	if (s > d && s - d < (int)n) {
		i = 0;
		while (--i >= 0) {
			d[i] = s[i];
			i++;
		}

		return dest;
	}

	ft_memcpy(dest, src, n);
	return dest;
}
