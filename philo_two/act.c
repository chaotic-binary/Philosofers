/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 20:23:23 by ttamesha          #+#    #+#             */
/*   Updated: 2021/02/02 01:07:13 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static void	ms_sleep(int ms)
{
	long t;

	t = get_time();
	usleep(1000);
	while (get_time() < t + ms)
		usleep(1000);
}

static void	*monitor(void *data)
{
	t_ph	*ph;

	ph = (t_ph *)data;
	while (42)
	{
		if (ph->prm->fed >= ph->prm->num)
		{
			sem_wait(ph->prm->lock_write);
			write(1, "ALL FED\n", 8);
			sem_post(ph->prm->end);
			return (NULL);
		}
		sem_wait(ph->lock_time);
		if (get_interval(ph->last_meal) > ph->prm->die)
		{
			print_state(ph, DIED);
			sem_post(ph->prm->end);
			return (NULL);
		}
		sem_post(ph->lock_time);
		usleep(1200);
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
	{
		sem_wait(ph->prm->lock_fed);
		++ph->prm->fed;
		sem_post(ph->prm->lock_fed);
	}
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
	if (init_thread(&monitor, ph, ph->prm->lock_write))
	{
		write(2, "Thread creation failed\n", 23);
		return (NULL);
	}
	while (42)
	{
		print_state(ph, THINK);
		eat(ph);
	}
	return (NULL);
}
