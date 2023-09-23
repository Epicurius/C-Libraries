/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 29/03/2023 Niklas Neronin
 * Updated: 23/09/2023 Niklas Neronin
 */

#include "liblg.h"

static const char *lg_levels[] = {
	"DEBUG",
	"INFO",
	"WARN",
	"ERROR"
};

static const char *lg_colors[] = {
	"\x1b[36m",
	"\x1b[32m",
	"\x1b[33m",
	"\x1b[31m"
};

struct g_log	lg_global = {NULL, -1, -1};

int	lg_openFile(char *file, char *mode)
{
	lg_global.fp = fopen(file, mode);
	if (lg_global.fp == NULL)
		return 0;

	LG_INFO("Log Opened.");
	return 1;
}

int	lg_closeFile(void)
{
	if (lg_global.fp == NULL)
		return 1;

	LG_INFO("Log Closed.");
	return fclose(lg_global.fp);
}

int	lg_setFile(FILE *fp)
{
	if (lg_global.fp && fp) {
		LG_INFO("File already set.");
		return 0;
	}

	lg_global.fp = fp;
	if (!lg_global.fp)
		LG_INFO("File pointer set to 'NULL'.");

	return 1;
}

void	lg_setLevel(int std, int file)
{
	lg_global.stdlvl = std;
	lg_global.filelvl = file;
}

void	lg_fwrite(int lvl, const char *file, int line, const char *time,
	const char *fmt, va_list ap)
{
	fprintf(lg_global.fp, "%s %-5s %s:%d\n", time, lg_levels[lvl], file, line);
	vfprintf(lg_global.fp, fmt, ap);
	fflush(lg_global.fp);
	fwrite("\n", 1, 1, LG_PRINT_STD);
}

void	lg_write(int lvl, const char *file, int line, const char *fmt,
	va_list ap)
{
	fprintf(LG_PRINT_STD, "%s%-5s\x1b[0m \x1b[90m%s:%d\x1b[0m\n",
			lg_colors[lvl], lg_levels[lvl], file, line);
	vfprintf(LG_PRINT_STD, fmt, ap);
	fflush(LG_PRINT_STD);
	fwrite("\n\n", 2, 1, LG_PRINT_STD);
}

void	lg_log(int lvl, const char *time, const char *file, int line,
	const char *fmt, ...)
{
	va_list ap;
	if (lvl >= lg_global.stdlvl)
	{
		va_start(ap, fmt);
		lg_write(lvl, file, line, fmt, ap);
		va_end(ap);
	}
	if (lg_global.fp && lvl >= lg_global.filelvl)
	{
		va_start(ap, fmt);
		lg_fwrite(lvl, file, line, time, fmt, ap);
		va_end(ap);
	}

	if (lvl == LEVEL_ERROR) {
		lg_closeFile();
		exit (1);
	}
}
