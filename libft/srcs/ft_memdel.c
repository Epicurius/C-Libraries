/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Frees allocated memory pointed to by 'ap'.
 */
void	ft_memdel(void **ap)
{
	if (ap != NULL) {
		free(*ap);
		*ap = NULL;
	}
}
