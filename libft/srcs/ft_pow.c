/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Returns decimal 'n' raised to the power 'pow'.
 */
double	ft_pow(double n, int pow)
{
	if (pow > 0)
		return (n * ft_pow(n, pow - 1));
	return 1;
}

/*
 * Returns integer 'n' raised to the power 'pow'.
 */
long double	ft_long_pow(long double n, int pow)
{
	long double	tmp;

	tmp = n;
	if (pow == 0)
		return 1;
	if (pow < 1)
		return 0;
	while (--pow)
		n *= tmp;
	return n;
}
