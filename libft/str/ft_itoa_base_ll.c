/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ll.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 01:58:30 by ttamesha          #+#    #+#             */
/*   Updated: 2020/10/01 09:00:14 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		*ft_itoa_base_ll(long long n, long long bs)
{
	char	*res;
	int		neg;
	int		sign;
	int		len;
	char	*digits;

	neg = n < 0 ? 1 : 0;
	sign = neg ? -1 : 1;
	digits = "0123456789ABCDEF";
	len = countdigits_base_ll(n, bs) + neg;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	if (neg == 1)
		res[0] = '-';
	res[len] = '\0';
	while (len > neg)
	{
		res[len - 1] = digits[(n % bs) * sign];
		len--;
		n = n / bs;
	}
	return (res);
}
