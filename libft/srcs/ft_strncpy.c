/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Copies 'n' bytes of the string pointed to by 'src' to 'dest'.
 */
char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t	size;

	size = 0;
	while (size < n && s2[size])
		size++;
	if (size != n)
		ft_memset(s1 + size, '\0', n - size);
	return (ft_memcpy(s1, s2, size));
}
