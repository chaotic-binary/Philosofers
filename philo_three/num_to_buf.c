/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_buf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:53:50 by ttamesha          #+#    #+#             */
/*   Updated: 2021/02/01 22:18:04 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

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

int				num_to_buf(char *buf, long n)
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
