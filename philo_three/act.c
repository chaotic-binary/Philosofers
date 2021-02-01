/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 20:23:23 by ttamesha          #+#    #+#             */
/*   Updated: 2021/02/01 23:43:06 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void	ms_sleep(int ms)
{
	long t;

	t = get_time();
	usleep(1000);
	while (get_time() < t + ms)
		usleep(1000);
}

static void	*monitor_death(void *data)
{
	t_ph	*ph;

	ph = (t_ph *)data;
	while (42)
	{
		sem_wait(ph->lock_time);
		if (get_interval(ph->last_meal) > ph->prm->die)
		{
			print_state(ph, DIED);
			sem_post(ph->prm->end);
			return (NULL);
		}
		sem_post(ph->lock_time);
		usleep(1100);
	}
	return (NULL);
}

static void	take_forks(t_ph *ph)
{
	sem_wait(ph->prm->book);
	sem_wait(ph->prm->frk);
	print_state(ph, FORK);
	sem_wait(ph->prm->frk);
	print_state(ph, FORK);
	sem_post(ph->prm->book);
}

static void	eat(t_ph *ph)
{
	take_forks(ph);
	print_state(ph, EAT);
	sem_wait(ph->lock_time);
	gettimeofday(&ph->last_meal, NULL);
	sem_post(ph->lock_time);
	ms_sleep(ph->prm->eat);
	if (++ph->meals == ph->prm->meals)
		sem_post(ph->prm->fed);
	sem_post(ph->prm->frk);
	sem_post(ph->prm->frk);
	print_state(ph, SLEEP);
	ms_sleep(ph->prm->sleep);
}

void		*act(void *data)
{
	t_ph *ph;

	ph = (t_ph *)data;
	gettimeofday(&ph->last_meal, NULL);
	if (init_thread(&monitor_death, ph, ph->prm->lock_write))
		exit(ERR_THREAD);
	while (42)
	{
		print_state(ph, THINK);
		eat(ph);
	}
	return (NULL);
}
