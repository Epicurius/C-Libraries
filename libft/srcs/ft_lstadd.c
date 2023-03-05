/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Add node 'new' to list 'alst'.
 */
int	ft_lstadd(t_list **alst, t_list *new)
{
	if (!new || !alst)
		return 1;

	if (!(*alst)) {
		(*alst) = new;
		(*alst)->next = NULL;
		(*alst)->prev = NULL;
	} else {
		new->next = (*alst);
		new->prev = NULL;
		(*alst)->prev = new;
		(*alst) = new;
	}

	return 0;
}
