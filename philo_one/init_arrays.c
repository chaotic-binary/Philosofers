#include "philo_one.h"

int			frk_init(t_ctrl *ctrl)
{
	int i;

	i = 0;
	if (!(ctrl->frk = malloc(sizeof(t_frk) * ctrl->prm->num)))
		return (ERR_MALLOC);
	while (i < ctrl->prm->num)
	{
		ctrl->frk->last_user = -1;
		if (pthread_mutex_init(&ctrl->frk->lock, NULL))
			return (ERR_MUTEX);
		++i;
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
		ctrl->ph[i].f1 = &(ctrl->frk[i]);
		ctrl->ph[i].f2 = &(ctrl->frk[(i == 0) ? ctrl->prm->num - 1 : i - 1]);
		ctrl->ph[i].prm = ctrl->prm;
		++i;
	}
	if (pthread_mutex_init(&ctrl->prm->lock_write, NULL) || \
		pthread_mutex_init(&ctrl->prm->lock_die, NULL))
		return (ERR_MUTEX);
	return (0);
}
