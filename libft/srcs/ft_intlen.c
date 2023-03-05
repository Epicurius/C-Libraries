/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Returns length of unsigned integer 'x'. This is a faster version of
 * 'ft_nbrlen()'.
 */
int	ft_uintlen(unsigned int x)
{
	if (x >= 100000) {
		if (x >= 10000000) {
			if (x >= 1000000000)
				return 10;
			if (x >= 100000000)
				return 9;
			return 8;
		}
		if (x >= 1000000)
			return 7;
		return 6;
	}
	if (x >= 1000) {
		if (x >= 10000)
			return 5;
		return 4;
	}
	if (x >= 100)
		return 3;
	if (x >= 10)
		return 2;
	return 1;
}

/*
 * Return length of integer 'x'.
 */
int	ft_intlen(int x)
{
	if (x < 0)
		return ft_uintlen(-x);
	return ft_uintlen(x);
}
