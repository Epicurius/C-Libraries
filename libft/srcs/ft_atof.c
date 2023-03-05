/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Converts the initial portion of the string pointed to by 'str' to double.
 */
double	ft_atof(const char *str)
{
	char	*c;
	int		len;
	double	integral;
	double	fractal;

	c = (char *)str;
	integral = (double)abs(ft_atoi(c));
	while (*c && *c != '.')
		c++;

	if (*c == '.')
		c++;

	fractal = (double)abs(ft_atoi(c));
	len = ft_strlen(c);
	while (len--)
		fractal /= 10;

	if (str[0] == '-')
		return ((integral + fractal) * -1);

	return (integral + fractal);
}
