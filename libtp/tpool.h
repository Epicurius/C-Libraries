 /*
 * -*- coding: utf-8 -*-
 * vim: ts=4 sw=4 tw=80 et ai si
 * 
 * Created: 09/11/2020 Niklas Neronin
 * Updated: 26/03/2023 Niklas Neronin
 */

#ifndef TPOOL_H
# define TPOOL_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_task
{
	int					(*func)(void *);
	void				*arg;
	struct s_task		*next;
}						t_task;

typedef struct s_tpool
{
	pthread_t			*threads;
	t_task				*tasks;
	pthread_mutex_t		mutex;
	pthread_cond_t		task_cond;
	pthread_cond_t		main_cond;
	int					nb_threads;
	int					alive_threads;
	int					running_threads;
	int					stop;
	int					error;
}						t_tpool;

int						init_tpool(t_tpool *tpool, int amount);
t_task					*create_task(int (*func)(void *), void *arg);
t_task					*get_task(t_tpool *tpool);
void					do_task(t_tpool *tpool);
void					delet_task(t_task *task);
int						free_tpool(t_tpool *tpool);
void					*tpool_func(void *arg);
int						tpool_add(t_tpool *tpool,
							      int (*func)(void *), void *arg);
int						tpool_wait(t_tpool *tpool);
void					*tpool_bzero(void *arg, size_t n);
int						tpool_error(int i);

#endif
