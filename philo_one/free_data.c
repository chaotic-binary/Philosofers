#include "philo_one.h"

void	free_data(t_ctrl *ctrl)
{
	if (ctrl->ph)
		free(ctrl->ph);
	if (ctrl->frk)
		free(ctrl->frk);
}