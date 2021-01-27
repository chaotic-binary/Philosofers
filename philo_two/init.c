/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arrays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 20:09:29 by ttamesha          #+#    #+#             */
/*   Updated: 2021/01/27 20:11:16 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int sems_init(t_ctrl *ctrl)
{
	sem_unlink("book");
	sem_unlink("frk");
	sem_unlink("lock_write");
	sem_unlink("fed");
	sem_unlink("lock_stop");
	if ((ctrl->prm->book = sem_open("book", FLAGS, CHMOD, 1)) == SEM_FAILED)
		return (ERR_SEM);
	if ((ctrl->prm->frk = sem_open("frk", FLAGS, CHMOD, ctrl->prm->num)) == SEM_FAILED)
		return (ERR_SEM);
	if ((ctrl->prm->lock_write = sem_open("lock_write", FLAGS, CHMOD, 1)) == SEM_FAILED)
		return (ERR_SEM);
	if ((ctrl->prm->fed = sem_open("fed", FLAGS, CHMOD, 0)) == SEM_FAILED)
		return (ERR_SEM);
	if ((ctrl->prm->lock_stop = sem_open("lock_stop", FLAGS, CHMOD, 0)) == SEM_FAILED)
		return (ERR_SEM);
	return (0);
}

int	ph_init(t_ctrl *ctrl)
{
	int i;

	i = 0;
	if (!(ctrl->ph = malloc(sizeof(t_ph) * ctrl->prm->num)))
		return (ERR_MALLOC);
	while (i < ctrl->prm->num)
	{
		ctrl->ph[i].id = i + 1;
		ctrl->ph[i].meals = 0;
		ctrl->ph[i].prm = ctrl->prm;
		++i;
	}
	return (0);
}
