/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 20:35:43 by ttamesha          #+#    #+#             */
/*   Updated: 2021/01/27 22:03:34 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int	monitor(t_ctrl *ctrl)
{
	int		i;

	if (ctrl->prm->fed == ctrl->prm->num)
	{
		pthread_mutex_lock(&ctrl->prm->lock_write);
		write(1, "ALL FED\n", 8);
		return (1);
	}
	i = -1;
	while (++i < ctrl->prm->num)
	{
		if (get_interval(ctrl->ph[i].last_meal) > ctrl->prm->die)
		{
			print_state(&ctrl->ph[i], DIED);
			return (1);
		}
	}
	return (0);
}

static int	init_thread(void *(*f)(void *), void *ph,\
										pthread_mutex_t *lock)
{
	pthread_t	t;

	if (pthread_create(&t, NULL, f, ph))
	{
		pthread_mutex_lock(lock);
		return (ERR_THREAD);
	}
	pthread_detach(t);
	return (0);
}

static int	run_threads(t_ctrl *ctrl)
{
	int i;

	i = 0;
	gettimeofday(&ctrl->prm->start, NULL);
	while (i < ctrl->prm->num)
	{
		if (init_thread(&act, &ctrl->ph[i], &ctrl->prm->lock_write))
			return (ERR_THREAD);
		usleep(10);
		i++;
	}
	while (42)
	{
		usleep(1200);
		if (monitor(ctrl))
			return (0);
	}
	return (1);
}

int			main(int ac, char **av)
{
	t_prm	prm;
	t_ctrl	ctrl;
	int		ret;

	if (!prm_setup(ac, av, &prm, &ctrl))
		return (-1);
	if (!(ret = frk_init(&ctrl)))
		ret = ph_init(&ctrl);
	if (ret)
		return (ret);
	if (pthread_mutex_init(&ctrl.prm->lock_write, NULL))
	{
		free_data(&ctrl);
		return (ERR_MUTEX);
	}
	ret = run_threads(&ctrl);
	usleep(prm.delay);
	free_data(&ctrl);
	return (ret);
}
