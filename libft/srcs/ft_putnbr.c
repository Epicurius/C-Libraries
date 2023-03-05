/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Writes the integer 'n' to the standard output.
*/
void	ft_putnbr(int n)
{
	if (n < 0 && n != -2147483648) {
		ft_putchar('-');
		ft_putnbr(n * (-1));
	}
	else if (n == -2147483648) {
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else {
		if (n >= 10) {
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
		else
			ft_putchar(n + '0');
	}
}
