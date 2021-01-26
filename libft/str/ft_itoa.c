/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 01:58:30 by ttamesha          #+#    #+#             */
/*   Updated: 2020/10/01 20:11:42 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a string representing
** the integer received as an argument.
** Negative numbers must be handled.
** Parameters #1. the integer to convert.
** RETURN The string representing the integer. NULL if the allocation fails.
*/

#include "../libft.h"

char		*ft_itoa(int n)
{
	char	*res;
	int		neg;
	int		sign;
	int		len;

	neg = n < 0 ? 1 : 0;
	sign = neg ? -1 : 1;
	len = countdigits(n) + neg;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	if (neg == 1)
		res[0] = '-';
	res[len] = '\0';
	while (len > neg)
	{
		res[len - 1] = (n % 10) * sign + '0';
		len--;
		n = n / 10;
	}
	return (res);
}
