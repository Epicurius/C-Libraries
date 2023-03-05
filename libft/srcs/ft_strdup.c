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
char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*new;

	len = ft_strlen(s) + 1;
	if ((new = malloc(len)))
		return ((char *)ft_memcpy(new, s, len));
	return NULL;
}
