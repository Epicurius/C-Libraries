/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Returns length of 'x'.
 */
int	ft_nbrlen(long nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return 1;

	while (nbr != 0) {
		nbr /= 10;
		len++;
	}

	return len;
}
