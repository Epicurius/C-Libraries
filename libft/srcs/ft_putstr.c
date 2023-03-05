/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Writes string 's' to the standard output.
 */
void	ft_putstr(char const *s)
{
	write(1, s, ft_strlen(s));
}
