/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 20:05:29 by ttamesha          #+#    #+#             */
/*   Updated: 2021/01/27 21:41:14 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static size_t	ft_strcpy(char *dest, const char *src)
{
	const char *s;

	s = src;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	while (*src)
		src++;
	return (src - s);
}

void			print_state(t_ph *ph, int s)
{
	long		time;
	int			len;
	char		buf[100];
	const char	*state[] = {"is eating\n", \
							"is sleeping\n", \
							"is thinking\n", \
							"has taken a fork\n", \
							"died\n"};

	sem_wait(ph->prm->lock_write);
	time = get_interval(ph->prm->start);
	len = num_to_buf(buf, time);
	len = len + num_to_buf(&buf[len], ph->id);
	len = len + ft_strcpy(&buf[len], state[s]);
	write(1, buf, len);
	if (s != DIED)
		sem_post(ph->prm->lock_write);
}
