/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 01:58:30 by ttamesha          #+#    #+#             */
/*   Updated: 2020/10/01 08:53:45 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_putnbr_base_ll(long long n, long long bs)
{
	char	res[12];
	int		neg;
	int		len;
	int		i;
	char	*digits;

	neg = n < 0 ? 1 : 0;
	digits = "0123456789ABCDEF";
	len = countdigits_base_ll(n, bs) + neg;
	if (neg == 1)
		res[0] = '-';
	i = len;
	while (i > neg)
	{
		res[i - 1] = digits[(n % bs) * ((neg * -2) + 1)];
		i--;
		n = n / bs;
	}
	write(1, res, len);
}
