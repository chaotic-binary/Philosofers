#include "philo_one.h"

/*static void	ft_swap(t_frk *a, t_frk *b)
{
    t_frk *tmp;

    tmp = a;
    a = b;
    b = tmp;
}*/

int			frk_init(t_ctrl *ctrl)
{
	int i;

	i = 0;
	if (!(ctrl->frk = malloc(sizeof(t_frk) * ctrl->prm->num)))
		return (ERR_MALLOC);
	while (i < ctrl->prm->num)
	{
		ctrl->frk[i].last_user = -1;
        ctrl->frk[i].id = i;
		if (pthread_mutex_init(&ctrl->frk[i].lock, NULL))
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
		if (i % 2)
        {
            ctrl->ph[i].f1 = &(ctrl->frk[i - 1]);
            ctrl->ph[i].f2 = &(ctrl->frk[i]);
        }
		else
        {
            ctrl->ph[i].f1 = &(ctrl->frk[i]);
            ctrl->ph[i].f2 = &(ctrl->frk[(i == 0) ? ctrl->prm->num - 1 : i - 1]);
        }
		ctrl->ph[i].prm = ctrl->prm;
		++i;
	}
	if (pthread_mutex_init(&ctrl->prm->lock_write, NULL) || \
		pthread_mutex_init(&ctrl->prm->lock_die, NULL))
		return (ERR_MUTEX);
	return (0);
}
