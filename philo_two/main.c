/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 20:35:43 by ttamesha          #+#    #+#             */
/*   Updated: 2021/02/01 21:56:54 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static int	run_threads(t_ctrl *ctrl)
{
	int i;

	i = 0;
	gettimeofday(&ctrl->prm->start, NULL);
	while (i < ctrl->prm->num)
	{
		if (init_thread(&act, &ctrl->ph[i], ctrl->prm->lock_write))
			return (ERR_THREAD);
		usleep(10);
		i++;
	}
	sem_wait(ctrl->prm->end);
	return (0);
}

int			main(int ac, char **av)
{
	t_prm	prm;
	t_ctrl	ctrl;
	int		ret;

	if (!prm_setup(ac, av, &prm, &ctrl))
		return (-1);
	if (!(ret = ph_init(&ctrl)))
		ret = sems_init(&ctrl);
	if (ret)
	{
		if (ctrl.ph)
			free(ctrl.ph);
		return (ret);
	}
	ret = run_threads(&ctrl);
	usleep(prm.delay);
	free(ctrl.ph);
	return (ret);
}
