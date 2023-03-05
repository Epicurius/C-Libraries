/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Delete node 'del' from list 'alst'.
 */
int ft_lstdelnode(t_list **alst, void (*del)(void*, size_t))
{
	if (alst == NULL)
		return 1;

	(*alst)->prev->next = (*alst)->next;
	(*alst)->next->prev = (*alst)->prev;
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
	return 0;
}
