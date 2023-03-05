/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Allocates 'size' memory and returns a pointer to it.
*/
void	*ft_memalloc(size_t size)
{
	return ft_calloc(1, size);
}