
#include "philo_one.h"

void	ft_dlstadd_back(t_dlist *lst, t_dlist *new)
{
	t_dlist *last;

	if (!new || !lst)
		return ;
	if (!lst)
	{
		lst = new;
		return ;
	}
	last = lst;
	while (last->next)
	{
		last->prev->next = last->next;
		last->next->prev = last->prev;
		last = last->next;
	}
	new->prev = last;
	last->next = new;
}
