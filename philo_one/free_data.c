/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 20:02:27 by ttamesha          #+#    #+#             */
/*   Updated: 2021/01/27 22:03:10 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	free_data(t_ctrl *ctrl)
{
	int i;

	if (ctrl->ph)
		free(ctrl->ph);
	if (ctrl->frk)
		free(ctrl->frk);
	pthread_mutex_destroy(&ctrl->prm->lock_write);
	i = -1;
	while (++i < ctrl->prm->num)
		pthread_mutex_destroy(&ctrl->frk[i].lock);
}
