/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Returns string 'str' in reverse. 
 */
char    *ft_strrev(char *str)
{
    char *p1;
    char *p2;
	char tmp;

	p1 = str;
	p2 = str + ft_strlen(str) - 1;
    while (p1 < p2) {
        tmp = *p1;
        *p1++ = *p2;
        *p2-- = tmp;
    }
    return str;
}
