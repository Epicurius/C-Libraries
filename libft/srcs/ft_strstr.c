/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Locates the first occurrence of the substring 'haystack' in the string
 * 'needle' and returns a pointer to this position.
 */
char *ft_strstr(const char *haystack, const char *needle)
{
	size_t	c;

	if (*needle == 0 || haystack == needle)
		return (char *)haystack;
	c = ft_strlen(needle);
	while (*haystack) {
		if (!(ft_strncmp((char *)haystack, (char *)needle, c)))
			return (char *)haystack;
		haystack++;
	}
	return NULL;
}
