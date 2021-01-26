#include "philo_one.h"

long long get_time()
{
	struct timeval tm;

	gettimeofday(&tm, NULL);
	return (tm.tv_sec * 1000 + tm.tv_usec / 1000);
}

void eat(t_ph *ph)
{
	while (42) {printf("\n%d last1=%d, last2=%d\n ", ph->id,  ph->f1->last_user ,  ph->f2->last_user );
		if (ph->meals == ph->prm->meals)
			return;
		pthread_mutex_lock(&ph->f1->lock);
		if (ph->id == ph->f1->last_user)
			pthread_mutex_unlock(&ph->f1->lock);
		print_state(ph, FORK);
		pthread_mutex_lock(&ph->f2->lock);
		if (ph->id == ph->f2->last_user)
			pthread_mutex_unlock(&ph->f2->lock);
		print_state(ph, FORK);
		print_state(ph, EAT);
		ph->last_meal = get_time();
		//ft_dlstadd_back(&ph->prm->lst, ph);
		ph->f1->last_user = ph->id;
		ph->f2->last_user = ph->id;
		if (++ph->meals == ph->prm->meals)
			++ph->prm->fed;
		usleep(ph->prm->eat);
		pthread_mutex_unlock(&ph->f1->lock);
		pthread_mutex_unlock(&ph->f2->lock);
		pthread_mutex_lock(&ph->prm->lock_write);
		print_state(ph,SLEEP);
		pthread_mutex_unlock(&ph->prm->lock_write);
		usleep(ph->prm->sleep);
	}
}

void *act(void *data)
{
	t_ph *ph;

	ph = (t_ph *)data;
    ph->last_meal = get_time();
	eat(ph);
	pthread_mutex_lock(&ph->prm->lock_write);
	print_state(ph,THINK);
	pthread_mutex_unlock(&ph->prm->lock_write);
	return (NULL);
}

int monitor(void *data)
{
	t_ctrl *ctrl;
	int i;

	ctrl = (t_ctrl *)data;
	//printf("\nf=%d ", ctrl->prm->fed);
	if (ctrl->prm->fed == ctrl->prm->num)
	{
		pthread_mutex_lock(&ctrl->prm->lock_write);
		printf("FED\n");
		return (1);
	}
	i = -1;
	while (++i < ctrl->prm->num)
    { //printf("%lu, %lu, %d\n", get_time(),  ctrl->ph[i].last_meal, get_time() - ctrl->ph[i].last_meal );
	    if (get_time() - ctrl->ph[i].last_meal > ctrl->prm->die)
        {
	        printf("%lu, %lu, %d\n", get_time(),  ctrl->ph[i].last_meal, ctrl->prm->die);
            pthread_mutex_lock(&ctrl->prm->lock_write);
            print_state(&ctrl->ph[i], DIED);
            usleep(ctrl->prm->delay);
            return (1);
        }
    }
	return (0);
}


static int	init_thread(void *(*f)(void *), void *ph,\
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
	ctrl->prm->start = get_time();
	while (i < ctrl->prm->num)
	{
		if (init_thread(&act, &ctrl->ph[i], &ctrl->prm->lock_write))
			return (ERR_THREAD);
		usleep(10);
		i++;
	}
	/* if (pthread_create(&t, NULL, &monitor, ctrl) || pthread_join(t, NULL))
	{
		pthread_mutex_lock(&ctrl->prm->lock_write);
		return (ERR_THREAD);
	}*/
	while (42)
	{
        if (monitor(ctrl))
            return (1);
    }
	return (0);
}

int			main(int ac, char **av)
{
	t_prm	prm;
	t_ctrl	ctrl;
	int		i;

	if (!prm_setup(ac, av, &prm, &ctrl))
		return (-1);
	if (frk_init(&ctrl) || ph_init(&ctrl))
		return (-1);
	i = -1;
    /*while (++i < ctrl.prm->num)
    {
        ctrl.prm->lst[i].content = &ctrl.ph[i];
        if (i != ctrl.prm->num - 1)
            ctrl.prm->lst[i].next = &ctrl.prm->lst[i + 1];
        else
            ctrl.prm->lst[i].next = NULL;
        if (i)
            ctrl.prm->lst[iprev = &ctrl.prm->lst[i - 1];
    }
    /*for (int i = 0; i < ctrl.prm->num; ++i)
    {
        printf("%p\n", ctrl.prm->lst[i].next->content);
        ctrl.prm->lst[i].next;
    }*/
	//for (int i = 0; i < ctrl.prm->num; ++i)
	//	printf("\n frk=%d, last=%d\n ", ctrl.frk[i].id, ctrl.frk[i].last_user);
	for (int i = 0; i < ctrl.prm->num; ++i)
		printf("\n%d f1=%d, f2=%d, f1=%p, f1=%p\n ", ctrl.ph[i].id-1, ctrl.ph[i].f1->id ,  ctrl.ph[i].f2->id,  ctrl.ph[i].f1->lock, ctrl.ph[i].f2->lock);
	run_threads(&ctrl);
	return (0);
}
