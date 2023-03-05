/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 25/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Copies part of the string 'str', beginning at the location specified by
 * 'start'. The parameter 'len' specifies the number of characters to copy.
 */
char	*ft_strsub(char const *str, int start, int len)
{
	char	*ptr;
	char	*new;
	int		i;

	if (!str)
		return NULL;
	len = ft_min(ft_strlen(str + start), len);
	new = malloc(len + 1);
	if (!new)
		return NULL;
	i = -1;
	ptr = (char *)&str[start];
	while (++i < len)
		new[i] = *ptr++;
	new[i] = '\0';
	return new;
}
