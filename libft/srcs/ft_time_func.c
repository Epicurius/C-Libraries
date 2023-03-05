/*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 05/03/2023 Niklas Neronin
 * Updated: 19/03/2023 Niklas Neronin
 */

#include <time.h>
#include <stdio.h>

clock_t	g_clock_start;

/*
 * Start timing. 
 */
void	ft_timer_start(void)
{
	g_clock_start = clock();
}

/*
 * End timer and return elapsed time in seconds.
 */
double	ft_timer_end(void)
{
	double	cpu_time_used;
	clock_t	end;

	end = clock();
	cpu_time_used = ((double)(end - g_clock_start)) / CLOCKS_PER_SEC;
	return cpu_time_used;
}
