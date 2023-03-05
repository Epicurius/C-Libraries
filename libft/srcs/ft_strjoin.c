/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"
#include <stdio.h>

/*
 * Combines string 'str1' and 'str2'.
 */
char *ft_strjoin(const char *str1, const char *str2)
{
	int	 l1;
	int  l2;
	char *new;

	l1 = ft_strlen(str1);
	l2 = ft_strlen(str2);
    if ((new = malloc(l1 + l2 + 1))) {
		ft_memcpy(new, str1, l1 + 1);
		if (l2)
			ft_memcpy(new + l1, str2, l2 + 1);
	}
    return new;
}
