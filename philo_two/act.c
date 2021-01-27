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

#include "philo_two.h"

static void	ms_sleep(int ms)
{
	long			t;

	t = get_time();
	usleep(1000);
	while (get_time() < t + ms)
		usleep(1000);
}

static void	take_forks(t_frk *frk, t_ph *ph)
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

	if (++ph->meals == ph->prm->meals)
		++ph->prm->fed;
	gettimeofday(&ph->last_meal, NULL);
	ms_sleep(ph->prm->eat);


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
