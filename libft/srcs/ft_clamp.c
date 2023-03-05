/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

static double	ft_fclamp2(double x, double min, double max)
{
	if (x < min)
		return min;
	if (x > max)
		return max;
	return x;
}

/*
 *	Clamp decimal 'x' between 'a' and 'b'.
 */
double	ft_fclamp(double x, double a, double b)
{
	if (a > b)
		return ft_fclamp2(x, b, a);
	else if (a < b)
		return ft_fclamp2(x, a, b);
	else
		return a;
}

static int	ft_clamp2(int x, int min, int max)
{
	if (x < min)
		return min;
	if (x > max)
		return max;
	return x;
}

/*
 *	Clamp integer 'x' between 'a' and 'b'.
 */
int	ft_clamp(int x, int a, int b)
{
	if (a > b)
		return ft_clamp2(x, b, a);
	else if (a < b)
		return ft_clamp2(x, a, b);
	else
		return a;
}
