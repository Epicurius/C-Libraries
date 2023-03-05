/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Appends 'n' amount of 'src' string to the (pre-allocated) 'dest' string.
 */
char	*ft_strncat(char *dest, const char *src, size_t n)
{
	ft_strncpy(dest + ft_strlen(dest), src, n);
	return dest;
}
