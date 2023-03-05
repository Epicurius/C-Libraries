/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Allocates and returns a new link. The variables content and content_size of
 * the new link are initialized by copy of the parameters of the function. If
 * the parameter content is NULL, the variable content is initialized to NULL
 * and the variable content_size is initialized to 0 even if the parameter
 * content_size isn’t. The variable next is initialized to NULL.
 */
t_list	*ft_lstnew(void	const *content, size_t content_size)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if (new) {
		if (!content) {
			new->prev = NULL;
			new->content = NULL;
			new->content_size = 0;
		}
		else {
			if (!(new->content = malloc(content_size))) {
				free(new);
				return NULL;
			}
			ft_memcpy(new->content, content, content_size);
			new->content_size = content_size;
		}
		new->next = NULL;
		return new;
	}
	return NULL;
}