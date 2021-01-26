/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countdigits_base_ll.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 08:54:10 by ttamesha          #+#    #+#             */
/*   Updated: 2020/10/01 09:00:52 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	countdigits_base_ll(long long n, long long bs)
{
	int count;

	count = 1;
	while (n / bs != 0)
	{
		count++;
		n /= bs;
	}
	return (count);
}
