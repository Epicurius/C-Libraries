/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Writes 'n' bytes of value 'c' to the string 'str'.
*/
void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char *ptr;

	ptr = (unsigned char*)str;
	while (n-- > 0)
		*ptr++ = (unsigned char)c;
	return str;
}
