/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 *
 * Created: 14/05/2021 Niklas Neronin
 * Updated: 26/03/2023 Niklas Neronin
 */

#include "libpf.h"

int	ft_vprintf(const char *restrict format, va_list ap)
{
	return ft_vfprintf(stdout, format, ap);
}

int	ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	int		len;

	if (!format)
		return -1;
	va_start(ap, format);
	len = ft_vfprintf(stdout, format, ap);
	va_end(ap);
	return len;
}
