/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Delete node 'del' from 'lst' and relink if necessary.
 */
t_list	*ft_dellstnode(t_list **lst, t_list *del)
{
	t_list	*next;

	next = NULL;
	if (!del->prev && !del->next)
		(*lst) = NULL;
	else if (del->next && del->prev) {
		del->next->prev = del->prev;
		del->prev->next = del->next;
	}
	else if (del->next) {
		(*lst) = del->next;
		del->next->prev = NULL;
	}
	else if (del->prev)
		del->prev->next = NULL;

	if ((*lst))
		next = del->next;

	free(del->content);
	free(del);
	return next;
}
