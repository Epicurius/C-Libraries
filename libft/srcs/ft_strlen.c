/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*(str++))
		len++;
	return len;
}
