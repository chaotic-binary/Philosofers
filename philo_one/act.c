/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 20:23:23 by ttamesha          #+#    #+#             */
/*   Updated: 2021/01/27 20:33:14 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void	ms_sleep(int ms)
{
	long t;

	t = get_time();
	usleep(1000);
	while (get_time() < t + ms)
		usleep(1000);
}

static void	take_fork(t_frk *frk, t_ph *ph)
{
	while (1)
	{
		pthread_mutex_lock(&frk->lock);
		if (ph->id == frk->last_user)
		{
			pthread_mutex_unlock(&frk->lock);
			usleep(1000);
			continue ;
		}
		print_state(ph, FORK);
		break ;
	}
}

static void	eat(t_ph *ph)
{
	take_fork(ph->f1, ph);
	take_fork(ph->f2, ph);
	print_state(ph, EAT);
	ph->f1->last_user = ph->id;
	ph->f2->last_user = ph->id;
	if (++ph->meals == ph->prm->meals)
		++ph->prm->fed;
	gettimeofday(&ph->last_meal, NULL);
	ms_sleep(ph->prm->eat);
	pthread_mutex_unlock(&ph->f1->lock);
	pthread_mutex_unlock(&ph->f2->lock);
	print_state(ph, SLEEP);
	ms_sleep(ph->prm->sleep);
}

void		*act(void *data)
{
	t_ph *ph;

	ph = (t_ph *)data;
	gettimeofday(&ph->last_meal, NULL);
	while (42)
	{
		print_state(ph, THINK);
		if (ph->meals == ph->prm->meals)
			return (NULL);
		eat(ph);
	}
	return (NULL);
}
