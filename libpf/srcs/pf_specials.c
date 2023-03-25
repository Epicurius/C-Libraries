/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 *
 * Created: 15/05/2021 Niklas Neronin
 * Updated: 26/03/2023 Niklas Neronin
 */

#include "libpf.h"

static const t_pf_style	g_pf_styles[11] =
{
	{"{RESET}", "\x1b[0m", 7},
	{"{RED}", "\x1b[31m", 5},
	{"{GREEN}", "\x1b[32m", 7},
	{"{YELLOW}", "\x1b[33m", 8},
	{"{BLUE}", "\x1b[34m", 6},
	{"{MAGENTA}", "\x1b[35m", 9},
	{"{CYAN}", "\x1b[36m", 6},
	{"{BOLD}", "\x1b[1m", 6},
	{"{ITALIC}", "\x1b[3m", 8},
	{"{UND}", "\x1b[4m", 5},
	{"{INVERT}", "\x1b[7m", 8}
};

static int	color_code(t_pf *p, int i)
{
	int	len;
	int	code;

	len = 0;
	code = ft_atoi(p->format + i);
	if (code >= 0 && code <= 9)
		len = 1;
	else if (code >= 10 && code <= 99)
		len = 2;
	else if (code >= 100 && code <= 255)
		len = 3;
	if (len == 0 || !ft_strncmp((p->format + i + len), "}", 1))
		return 0;
	if (fileno(p->fp) < 3) {
		fill_buffer(p, "\x1b[38;5;", 7);
		fill_buffer(p, p->format + i, len);
		fill_buffer(p, "m", 1);
	}
	p->format += i + len + 1 - 1;
	return 1;
}

static void	pf_style(t_pf *p, int i)
{
	i = -1;
	if (ft_strncmp(&*p->format, "{CLR:", 5) && color_code(p, 5))
		return ;
	while (++i < 11) {
		if (ft_strncmp(g_pf_styles[i].str, &*p->format, g_pf_styles[i].len)) {
			if (fileno(p->fp) < 3)
				fill_buffer(p, g_pf_styles[i].code, 5);
			p->format += g_pf_styles[i].len - 1;
			return ;
		}
	}
	fill_buffer(p, p->format, 1);
}

void	pf_specials(t_pf *p)
{
	if (*p->format == '{' && (*p->format + 1) && ft_isupper(*(p->format + 1)))
		pf_style(p, -1);
	else
		fill_buffer(p, p->format, 1);
}