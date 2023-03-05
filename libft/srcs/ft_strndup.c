/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Return copy of string 'str'.
 */
char	*ft_strndup(const char *s, size_t n)
{
	char	*new;

	if ((new = malloc(n + 1))) {
		new[n] = '\0';
		return ((char *)ft_memcpy(new, s, n));
	}
	return NULL;
}
