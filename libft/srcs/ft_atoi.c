/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Converts the string argument 'str' to an integer and returns it.
 */
int	ft_atoi(const char *str)
{
	int	nbr;
	int	sign;
	char *s;

	s = (char *)str;
	while (*s == ' ' || (*s > 8 && *s < 14))
		s++;

	sign = 1;
	if (*s == '+')
		s++;
	else if (*s == '-') {
		s++;
		sign = -1;
	}

	nbr = 0;
	while (*s >= '0' && *s <= '9') {
		nbr = (nbr * 10) + (*s - '0');
		s++;
	}

	return (nbr * sign);
}

