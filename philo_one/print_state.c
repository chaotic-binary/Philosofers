#include "philo_one.h"

void	print_state(int i)
{
	const char *state[] = {	"\e[93m is eating\n\e[0m", \
							"\e[94m is sleeping\n\e[0m", \
							"\e[96m is thinking\n\e[0m", \
							"\e[92m has taken a fork\n\e[0m", \
							"\e[91m died\n\e[0m"};

	write(1, state[i], ft_strlen(state[i]));
}