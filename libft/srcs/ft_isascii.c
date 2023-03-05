/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Return 'True' if 'c' is an ASCII character.
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
