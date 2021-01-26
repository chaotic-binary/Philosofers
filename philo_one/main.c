#include "philo_one.h"

void *act(void *data)
{
	t_ph *ph;

	ph = (t_ph *)data;

}

void *monitor(void *data)
{
	t_ctrl *ctrl;

	ctrl = (t_ctrl *)data;

}


static int			init_thread(void *(*f)(void *), void *ph,\
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

int			run_threads(t_ctrl *ctrl)
{
	pthread_t	t;
	int			i;

	i = 0;
	gettimeofday(&ctrl->prm->start, NULL);
	while (i < ctrl->prm->num)
	{
		if (init_thread(&act, &ctrl->ph[i], &ctrl->prm->lock_write))
			return (ERR_THREAD);
		usleep(10);
		i++;
	}
	if (pthread_create(&t, NULL, &monitor, ctrl) ||\
							pthread_join(t, NULL))
	{
		pthread_mutex_lock(&ctrl->prm->lock_write);
		return (ERR_THREAD);
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_prm	prm;
	t_ctrl	ctrl;

	if (!prm_setup(ac, av, &prm, &ctrl))
		return (-1);
	if (frk_init || ph_init)
		return (-1);
	run_threads(&ctrl);
	return (0);
}