/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 29/03/2023 Niklas Neronin
 * Updated: 29/03/2023 Niklas Neronin
 */

#ifndef LIBLG_H
# define LIBLG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

enum
{
	LEVEL_DEBUG,
	LEVEL_INFO,
	LEVEL_WARN,
	LEVEL_ERROR
};

# define LG_PRINT_STD	stderr 

# define LG_DEBUG(...)	lg_log(LEVEL_DEBUG, __TIME__, __FILE__, __FUNCTION__, \
							   __LINE__, __VA_ARGS__)
# define LG_INFO(...)	lg_log(LEVEL_INFO,	__TIME__, __FILE__, __FUNCTION__, \
							   __LINE__, __VA_ARGS__)
# define LG_WARN(...)	lg_log(LEVEL_WARN,	__TIME__, __FILE__, __FUNCTION__, \
							   __LINE__, __VA_ARGS__)
# define LG_ERROR(...)	lg_log(LEVEL_ERROR, __TIME__, __FILE__, __FUNCTION__, \
							   __LINE__, __VA_ARGS__)

typedef struct s_lgEvent
{
	va_list		ap;
	const char	*fmt;
	const char	*time;
	const char	*file;
	const char	*func;
	int			line;
	int			lvl;
}				lg_event;

typedef struct g_log
{
	FILE		*fp;
	int			stdlvl;
	int			filelvl;
}				g_log;

/* File: ./liblg.c */
int			lg_openFile(char *file, char *mode);
void		lg_addFile(FILE *fp);
void		lg_closeFile(void);
void		lg_setLevel(int std, int file);
void		lg_log(int lvl, const char *time, const char *file,
				   const char *func, int line, const char *fmt, ...);
#endif
