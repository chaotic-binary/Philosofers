#include "philo_one.h"

void	print_state(t_ph *ph, int s)
{
    long long time;
    const char *state[] = {	"\e[93m is eating\n\e[0m", \
							"\e[94m is sleeping\n\e[0m", \
							"\e[96m is thinking\n\e[0m", \
							"\e[92m has taken a fork\n\e[0m", \
							"\e[91m died\n\e[0m"};

    time = get_time() - ph->prm->start;
    //pthread_mutex_lock(&ph->prm->lock_write);
    printf("%llu %d%s", time, ph->id, state[s]);
    //pthread_mutex_unlock(&ph->prm->lock_write);
}
