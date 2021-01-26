#include "philo_one.h"

int err_msg(int err_type)
{
	if (err_type == ERR_MALLOC)
		ft_putendl("Allocation error", 2);
	return (err_type);
}