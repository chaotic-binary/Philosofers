#include "philo_one.h"

int err_msg(int err_type)
{
	if (err_type == ERR_MALLOC)
		write(2, "Allocation error", 16);
	return (err_type);
}
