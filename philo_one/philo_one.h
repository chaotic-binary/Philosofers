/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 20:16:51 by ttamesha          #+#    #+#             */
/*   Updated: 2021/01/27 21:09:59 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

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
	ERR_MUTEX = -4
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
	pthread_mutex_t	lock_die;
	pthread_mutex_t	lock_write;
	int				fed;
}					t_prm;

typedef	struct		s_ph
{
	int				id;
	struct timeval	last_meal;
	struct s_frk	*f1;
	struct s_frk	*f2;
	int				meals;
	struct s_prm	*prm;
}					t_ph;

typedef struct		s_frk
{
	pthread_mutex_t	lock;
	int				last_user;
}					t_frk;

typedef struct		s_ctrl
{
	struct s_ph		*ph;
	struct s_frk	*frk;
	struct s_prm	*prm;
}					t_ctrl;

int					prm_setup(int ac, char **av, t_prm *prm, t_ctrl *ctrl);
int					frk_init(t_ctrl *ctrl);
int					ph_init(t_ctrl *ctrl);
void				*act(void *data);
void				free_data(t_ctrl *ctrl);
void				print_state(t_ph *ph, int status);
long				get_time();
long				get_interval(struct timeval t);

#endif
