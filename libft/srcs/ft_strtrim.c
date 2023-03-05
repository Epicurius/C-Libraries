/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 25/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Returns a copy of 'str' from byte 'start' to 'end'.
 */
char *ft_strtrim(char *str, int start, int end)
{
	char	*new;
	int		len;

	len = end - start;
	if (!str || len <= 0)
		return NULL;

	if ((new = malloc(len + 1))) {
		ft_memcpy(new, &str[start], len);
		new[len] = '\0';
		return new;
	}
	return NULL;
}
