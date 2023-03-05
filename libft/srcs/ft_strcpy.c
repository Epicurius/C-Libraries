/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 25/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Copies the string pointed to by 'src' to 'dest'.
 */
char *ft_strcpy(char *dest, const char *src)
{
	return (ft_memcpy(dest, src, ft_strlen(src) + 1));
}
