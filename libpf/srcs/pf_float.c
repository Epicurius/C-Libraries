/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 *
 * Created: 14/05/2021 Niklas Neronin
 * Updated: 29/03/2023 Niklas Neronin
 */

#include "libpf.h"
#include <math.h>

static long double	pf_integer(t_pf *p, long double nb)
{
	long	integer;

	if (p->precision == -1)
		p->precision = 6;
	integer = (long)nb;
	set_float_padding(p, integer, nb);
	put_left_spaces(p);
	if (p->padding.sign) {
		if (nb < 0 || 1.0 / nb < 0)
			fill_buffer(p, "-", 1);
		else if (p->flag.plus)
			fill_buffer(p, "+", 1);
		else if (p->flag.space)
			fill_buffer(p, " ", 1);
	}
	put_zeros(p);
	return ((long double)integer);
}

static long double	cast_float(t_pf *p)
{
	long double	nb;

	if (p->size_bytes == 16)
		nb = va_arg(p->ap, long double);
	else
		nb = va_arg(p->ap, double);
	return nb;
}

static int	pf_float_decimal(t_pf *p, long long nb, int precision)
{
	int		i, a, b;
	char	str[48];
	char	tmp;

	i = 0;
	while (nb > 0) {
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
		i++;
	}
	while (i < precision)
		str[i++] = '0';

	for (a = 0, b = i - 1; a < b; a++, b--) {
		tmp = str[a];
		str[a] = str[b];
		str[b] = tmp;
	}
	str[i++] = '\0';
	fill_buffer(p, str, precision);
	return i;
}

static int	pf_float_integer(t_pf *p, long nb)
{
	int		i, a, b;
	int		size;
	char	str[48];
	char	tmp;

	i = 0;
	size = ft_nbrlen(nb);
	if (nb == 0) {
		fill_buffer(p, "0", 1);
		return 1;
	}
	if (nb > 0)
		nb = -nb;
	while (nb < 0) {
		str[i++] = '0' - (nb % 10);
		nb = nb / 10;
	}

	for (a = 0, b = i - 1; a < b; a++, b--) {
		tmp = str[a];
		str[a] = str[b];
		str[b] = tmp;
	}
	str[i] = '\0';
	fill_buffer(p, str, size);
	return i + 1;
}

void	pf_float(t_pf *p)
{
	long double		nb;
	long			integer;
	long double		decimal;

	nb = cast_float(p);
	if (pf_nbr_inf(p, nb))
		return ;
	if (!p->precision && nb > 0)
		nb += 0.4999999;
	else if (!p->precision && nb < 0)
		nb -= 0.4999999;
	integer = pf_integer(p, nb);
	decimal = nb - integer;
	if (p->precision != 0)
		decimal = fabsl(decimal) * ft_long_pow(10, p->precision) + 0.5;
	if (ft_nbrlen((long)decimal) > p->precision && 0 < p->precision) {
		integer += 1;
		decimal = 0;
	}
	pf_float_integer(p, integer);
	if (p->precision != 0 || p->flag.hash)
		fill_buffer(p, ".", 1);
	pf_float_decimal(p, decimal, p->precision);
	put_right_spaces(p);
}
