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

static void	lg_write(lg_event *ev)
{
	char		buff[100];

	vsnprintf(buff, 100, ev->fmt, ev->ap);
	if (ev->lvl >= lg_global.stdlvl) {
		fprintf(LG_PRINT_STD, "%s[%-5s]\x1b[0m \x1b[90m%s:%d\x1b[0m : ",
			lg_colors[ev->lvl], lg_levels[ev->lvl], ev->func, ev->line);
		fprintf(LG_PRINT_STD, "%s\n", buff);
		fflush(LG_PRINT_STD);
	}
	if (lg_global.fp && ev->lvl >= lg_global.filelvl) {
		fprintf(lg_global.fp, "%s %-5s:\t\t%s\t\t",
			ev->time, lg_levels[ev->lvl], buff);
		fprintf(lg_global.fp, "[%s : %s : %d]\n", ev->file, ev->func, ev->line);
		fflush(lg_global.fp);
	}
}

void	lg_log(int lvl, const char *time, const char *file, const char *func,
	           int line, const char *fmt, ...)
{
	lg_event	ev;

	if ((lg_global.fp && lvl >= lg_global.filelvl) || lvl >= lg_global.stdlvl) {
		ev.fmt = fmt;
		ev.time = time;
		ev.file = file;
		ev.func = func;
		ev.line = line;
		ev.lvl = lvl;
		va_start(ev.ap, fmt);
		lg_write(&ev);
		va_end(ev.ap);
	}
	if (lvl == LEVEL_ERROR)
		exit(1);
}
