/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 20:09:29 by ttamesha          #+#    #+#             */
/*   Updated: 2021/02/01 22:18:22 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int			init_thread(void *(*f)(void *), void *ph, sem_t *lock)
{
	pthread_t	t;

	if (pthread_create(&t, NULL, f, ph))
	{
		sem_wait(lock);
		return (ERR_THREAD);
	}
	pthread_detach(t);
	return (0);
}

static int	sem_create(sem_t **sem, const char *name, int n)
{
	sem_unlink(name);
	if ((*sem = sem_open(name, FLG, CHMD, n)) == SEM_FAILED)
		return (ERR_SEM);
	return (0);
}

static void	generate_name(char *buf, int i)
{
	int len;

	len = num_to_buf(buf, i);
	buf[len - 1] = '\0';
}

int			sems_init(t_ctrl *ctrl)
{
	int		i;
	char	buf[12];

	if (sem_create(&ctrl->prm->book, "book", 1))
		return (ERR_SEM);
	if (sem_create(&ctrl->prm->frk, "frk", ctrl->prm->num))
		return (ERR_SEM);
	if (sem_create(&ctrl->prm->lock_write, "lock_write", 1))
		return (ERR_SEM);
	if (sem_create(&ctrl->prm->lock_fed, "fed", 1))
		return (ERR_SEM);
	if (sem_create(&ctrl->prm->end, "end", 0))
		return (ERR_SEM);
	i = -1;
	while (++i < ctrl->prm->num)
	{
		generate_name(buf, ctrl->ph[i].id);
		if (sem_create(&ctrl->ph[i].lock_time, buf, 1))
			return (ERR_SEM);
	}
	return (0);
}

int			ph_init(t_ctrl *ctrl)
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
