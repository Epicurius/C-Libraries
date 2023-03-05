/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Copies 'n' bytes from 'src' to 'dest', with no error prevention.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dptr;
	unsigned char	*sptr;

	dptr = (unsigned char *)dest;
	sptr = (unsigned char *)src;
	if (!n || dest == src)
		return dest;

	while (n--)
		*dptr++ = *sptr++;

	return dest;
}
