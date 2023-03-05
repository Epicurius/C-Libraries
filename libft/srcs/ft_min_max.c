/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

double	ft_min(double a, double b)
{
	if (a < b)
		return a;
	return b;
}

double	ft_max(double a, double b)
{
	if (a > b)
		return a;
	return b;
}
