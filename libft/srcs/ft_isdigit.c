/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Returns 'True' if 'c' is a numeric character (0-9).
 */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
