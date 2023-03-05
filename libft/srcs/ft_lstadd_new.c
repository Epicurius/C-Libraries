/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Allocate and add new node to list.
 */
int	ft_lstadd_new(t_list **list, void *content, size_t content_size)
{
	t_list *new;

	if (content == NULL)
		return 0;

	new = malloc(sizeof(*new));
	if (!new)
		return 0;

	new->content = content;
	new->content_size = content_size;
	ft_lstadd(list, new);

	return 1;
}
