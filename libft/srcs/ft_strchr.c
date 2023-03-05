/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "libft.h"

/*
 * Searches for the first occurrence of the character 'c' in the string pointed
 to by the argument 'str'.
 */
char *ft_strchr(const char *str, int c)
{
	do {
		if (*str == c)
			return (char*)str;
  	} while (*str++);

  return 0;
}