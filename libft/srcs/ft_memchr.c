/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Searches for the first occurrence of the character 'c' in the first 'n' bytes
 * of the string 'str'. Returns a pointer to the matching byte or 'NULL'.
 */
void *ft_memchr(const void *str, int c, size_t n)
{
	size_t l;
	const char *s;

	s = (const char *)str;
	for (l = 0; l < n; l++)
		if (s[l] == c)
			return (void *)&s[l];

	return NULL;
}