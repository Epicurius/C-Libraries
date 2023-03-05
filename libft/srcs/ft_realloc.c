/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Attempts to resize the memory block pointed to by 'ptr'.
 */
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new;

	if (old_size == new_size)
		return ptr;

	new = malloc(new_size);
	if (!new) {
		ft_memdel(&ptr);
		return NULL;
	}

	ft_memset(new, 0, new_size);
	if (ptr)
		new = ft_memmove(new, ptr, old_size);

	ft_memdel(&ptr);
	return new;
}
