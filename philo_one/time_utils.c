/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 20:26:52 by ttamesha          #+#    #+#             */
/*   Updated: 2021/01/27 20:35:23 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

long	get_time(void)
{
	struct timeval tm;

	gettimeofday(&tm, NULL);
	return (tm.tv_sec * 1000 + tm.tv_usec / 1000);
}

long	get_interval(struct timeval t)
{
	struct timeval tm;

	gettimeofday(&tm, NULL);
	return ((tm.tv_sec - t.tv_sec) * 1000 + (tm.tv_usec - t.tv_usec) / 1000);
}
