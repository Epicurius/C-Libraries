/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Compares first 'n' bytes of string pointed to by 'str1' to the string
 * pointed to by 'str2'.
 */
int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
   	while (n != 0 && *s1 != '\0' && *s2 != '\0'  && *s1 == *s2) {
    	s1++;
    	s2++;
    	n--;
	}
	return n == 0 ? 0 : (*s1 - *s2);
}
