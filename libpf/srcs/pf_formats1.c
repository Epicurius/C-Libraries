/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 *
 * Created: 15/05/2021 Niklas Neronin
 * Updated: 26/03/2023 Niklas Neronin
 */

#include "libpf.h"

void	read_flags(t_pf *p)
{
	while (ft_strchr("-+# 0", *p->format)) {
		if (*p->format == '-')
			p->flag.minus = 1;
		else if (*p->format == '+')
			p->flag.plus = 1;
		else if (*p->format == ' ')
			p->flag.space = 1;
		else if (*p->format == '#')
			p->flag.hash = 1;
		else if (*p->format == '0')
			p->flag.zero = 1;
		p->format++;
	}
}

void	read_width(t_pf *p)
{
	int	nb;

	if (*p->format >= '1' && *p->format <= '9') {
		nb = ft_atoi(p->format);
		p->min_width = nb;
		while (*p->format >= '0' && *p->format <= '9')
			p->format++;
	}
}

void	read_precision(t_pf *p)
{
	int	nb;

	while (*p->format == '.')
		p->format++;
	if (*p->format >= '0' && *p->format <= '9') {
		nb = ft_atoi(p->format);
		p->precision = nb;
		while (*p->format >= '0' && *p->format <= '9')
			p->format++;
	}
	else if (*p->format == '*') {
		p->precision = va_arg(p->ap, int);
		if (p->precision < 0)
			p->precision = -1;
		p->format++;
	}
	else
		p->precision = 0;
}

void	read_wildcard(t_pf *p)
{
	p->min_width = va_arg(p->ap, int);
	if (p->min_width < 0) {
		p->flag.minus = 1;
		p->min_width = -p->min_width;
	}
	p->format++;
}
