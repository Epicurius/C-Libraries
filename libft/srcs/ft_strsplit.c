/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include "../libft.h"
#include <stdio.h>

static void	wc_and_cc(char *s, char c, int *wc, int *cc)
{
	*cc = 0;
	*wc = 0;
	while (*s) {
		if (*s && *s != c) {
			*wc += 1;
			while (*s && *s != c) {
				s++;
				*cc += 1;
			}
		}
		else
			s++;
	}
}

static char	**split(char *s, char c, int wc, int cc)
{
	void		*arr;
	const char	**ptrs;
	char		*data;

	arr = malloc(8 * (wc + 1) + (cc + wc));
	if (!arr)
		return NULL;
	ptrs = arr;
	data = arr + 8 * (wc + 1);
	while (*s) {
		if (*s != c) {
			*ptrs = data;
			while (*s && *s != c)
				*data++ = *s++;
			*data = '\0';
			data++;
			*++ptrs = NULL;
		}
		else
			s++;
	}
	return arr;
}

/*
 * Allocates and returns an array of strings obtained by splitting 'str' using
 * the character 'c' as a delimiter. Argument 'nb' will be set to number of
 * splits.
 */
char	**ft_ssplit(const char *str, char c, int *nb)
{
	int		wc;
	int		cc;
	char	*s;

	s = (char *)str;
	wc_and_cc(s, c, &wc, &cc);
	if (nb)
		*nb = wc;
	return (split(s, c, wc, cc));
}
