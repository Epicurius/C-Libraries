/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Return 'True' if 'c' is in an alphabet.
 */
int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c <= 'z' && c >= 'a'));
}
