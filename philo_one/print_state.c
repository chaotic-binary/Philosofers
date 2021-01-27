/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 20:05:29 by ttamesha          #+#    #+#             */
/*   Updated: 2021/01/27 20:07:45 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int		countdigits(long n)
{
	int count;

	count = 1;
	while (n / 10 != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

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

static int		itoa_buf(char *buf, long n)
{
	int len;
	int i;

	len = countdigits(n);
	i = len;
	while (i > 0)
	{
		buf[i - 1] = (n % 10) + '0';
		i--;
		n = n / 10;
	}
	buf[len++] = ' ';
	return (len);
}

void			print_state(t_ph *ph, int s)
{
	long		time;
	int			len;
	char		buf[256];
	const char	*state[] = {	"is eating\n", \
							"is sleeping\n", \
							"is thinking\n", \
							"has taken a fork\n", \
							"died\n"};

	pthread_mutex_lock(&ph->prm->lock_write);
	time = get_interval(ph->prm->start);
	len = itoa_buf(buf, time);
	len = len + itoa_buf(&buf[len], ph->id);
	len = len + ft_strcpy(&buf[len], state[s]);
	write(1, buf, len);
	if (s != DIED)
		pthread_mutex_unlock(&ph->prm->lock_write);
}
