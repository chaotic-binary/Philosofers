/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 20:35:43 by ttamesha          #+#    #+#             */
/*   Updated: 2021/02/03 16:53:42 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void	*monitor_fed(void *data)
{
	t_ctrl	*ctrl;
	int		i;

	ctrl = (t_ctrl *)data;
	i = -1;
	while (++i < ctrl->prm->num)
		sem_wait(ctrl->prm->fed);
	sem_wait(ctrl->prm->lock_write);
	write(1, "ALL FED\n", 8);
	sem_post(ctrl->prm->end);
	return (NULL);
}

static int	run_threads(t_ctrl *ctrl)
{
	int i;

	i = -1;
	gettimeofday(&ctrl->prm->start, NULL);
	while (++i < ctrl->prm->num)
	{
		if ((ctrl->ph[i].pid = fork()) == -1)
			exit(ERR_PROCESS);
		else if (ctrl->ph[i].pid == 0)
			act(&ctrl->ph[i]);
		usleep(10);
	}
	if (init_thread(&monitor_fed, ctrl, ctrl->prm->lock_write))
		exit(ERR_THREAD);
	sem_wait(ctrl->prm->end);
	usleep(ctrl->prm->delay);
	i = -1;
	while (++i < ctrl->prm->num)
		kill(ctrl->ph[i].pid, SIGTERM);
	return (0);
}

int			main(int ac, char **av)
{
	t_prm	prm;
	t_ctrl	ctrl;

	if (!prm_setup(ac, av, &prm, &ctrl))
		return (-1);
	ph_init(&ctrl);
	if (sems_init(&ctrl))
	{
		free_data(&ctrl);
		exit(ERR_SEM);
	}
	run_threads(&ctrl);
	free_data(&ctrl);
	return (0);
}
