/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Returns 'True' if 'c' is lower case.
 */
int	ft_islower(int c)
{
	return (c <= 'z' && c >= 'a');
}
