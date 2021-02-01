/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 20:16:51 by ttamesha          #+#    #+#             */
/*   Updated: 2021/02/01 22:18:55 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <fcntl.h>
# include <semaphore.h>

# define FLG	O_CREAT | O_EXCL
# define CHMD	S_IRUSR | S_IWUSR

enum	e_state
{
	EAT = 0,
	SLEEP = 1,
	THINK = 2,
	FORK = 3,
	DIED = 4
};

enum	e_error
{
	ERR_MALLOC = -2,
	ERR_THREAD = -3,
	ERR_SEM = -4
};

typedef	struct		s_prm
{
	int				num;
	int				die;
	int				eat;
	int				sleep;
	int				meals;
	int				delay;
	struct timeval	start;
	int				fed;
	sem_t			*frk;
	sem_t			*book;
	sem_t			*lock_fed;
	sem_t			*lock_write;
	sem_t			*end;
}					t_prm;

typedef	struct		s_ph
{
	int				id;
	struct timeval	last_meal;
	int				meals;
	struct s_prm	*prm;
	sem_t			*lock_time;
}					t_ph;

typedef struct		s_ctrl
{
	struct s_ph		*ph;
	struct s_prm	*prm;
}					t_ctrl;

int					prm_setup(int ac, char **av, t_prm *prm, t_ctrl *ctrl);
int					ph_init(t_ctrl *ctrl);
int					sems_init(t_ctrl *ctrl);
void				*act(void *data);
void				print_state(t_ph *ph, int status);
long				get_time();
long				get_interval(struct timeval t);
int					num_to_buf(char *buf, long n);
int					init_thread(void *(*f)(void *), void *ph, sem_t *lock);
#endif
