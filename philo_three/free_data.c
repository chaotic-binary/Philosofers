/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:52:12 by ttamesha          #+#    #+#             */
/*   Updated: 2021/02/03 16:52:20 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	free_data(t_ctrl *ctrl)
{
	int		i;
	char	buf[12];

	if (ctrl->ph)
		free(ctrl->ph);
	sem_unlink("book");
	sem_unlink("frk");
	sem_unlink("fed");
	sem_unlink("lock_write");
	sem_unlink("end");
	i = -1;
	while (++i < ctrl->prm->num)
	{
		generate_name(buf, ctrl->ph[i].id);
		sem_unlink(buf);
	}
}
