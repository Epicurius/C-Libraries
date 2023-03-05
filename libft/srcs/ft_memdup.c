/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Return copy of 'mem'.
 */
void	*ft_memdup(const void *mem, size_t size)
{
	void	*out;

	out = malloc(size);
	if (out != NULL)
		ft_memcpy(out, mem, size);

	return out;
}
