/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Find the last occurrence of char 'c' in string 'str'.
 */
char	*ft_strrchr(const char *str, int c)
{
	const char	*found;
	const char	*p;

	c = (unsigned char)c;
	if (c == '\0')
		return (ft_strchr(str, '\0'));
	found = NULL;
	p = ft_strchr(str, c);
	while (p != NULL) {
		found = p;
		str = p + 1;
		p = ft_strchr(str, c);
	}
	return ((char *)found);
}
