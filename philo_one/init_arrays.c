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

#include "philo_one.h"

int			frk_init(t_ctrl *ctrl)
{
	int i;

	i = 0;
	if (!(ctrl->frk = malloc(sizeof(t_frk) * ctrl->prm->num)))
		return (ERR_MALLOC);
	while (i < ctrl->prm->num)
	{
		ctrl->frk[i].last_user = -1;
		if (pthread_mutex_init(&ctrl->frk[i].lock, NULL))
		{
			free(ctrl->frk);
			return (ERR_MUTEX);
		}
		++i;
	}
	return (0);
}

static int	err_exit(t_ctrl *ctrl)
{
	int i;

	free(ctrl->frk);
	i = -1;
	while (++i < ctrl->prm->num)
		pthread_mutex_destroy(&ctrl->frk[i].lock);
	return (ERR_MALLOC);
}

int			ph_init(t_ctrl *ctrl)
{
	int i;

	i = 0;
	if (!(ctrl->ph = malloc(sizeof(t_ph) * ctrl->prm->num)))
		return (err_exit(ctrl));
	while (i < ctrl->prm->num)
	{
		ctrl->ph[i].id = i + 1;
		ctrl->ph[i].meals = 0;
		if (i % 2)
		{
			ctrl->ph[i].f1 = &(ctrl->frk[i - 1]);
			ctrl->ph[i].f2 = &(ctrl->frk[i]);
		}
		else
		{
			ctrl->ph[i].f1 = &(ctrl->frk[i]);
			ctrl->ph[i].f2 = &(ctrl->frk[(i == 0) ? \
							ctrl->prm->num - 1 : i - 1]);
		}
		ctrl->ph[i].prm = ctrl->prm;
		++i;
	}
	return (0);
}
