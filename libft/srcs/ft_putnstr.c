/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Writes 'n' amount of string 'str' to the standard output.
 */
void	ft_putnstr(char *str, int n)
{
	int	x;

	x = 0;
	if (*str == '\0')
		return ;

	if (n < 0)
		ft_putstr(str);
	else {
		while (x != n) {
			if (str[x] == '\0')
				return ;

			write(1, &str[x], 1);
			x++;
		}
	}
}
