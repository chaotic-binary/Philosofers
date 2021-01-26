/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 18:39:43 by ttamesha          #+#    #+#             */
/*   Updated: 2020/10/14 19:39:20 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

double	ft_atof(char *str)
{
	int		sign;
	double	nb;
	double	fraction;
	int		i;

	sign = 0;
	nb = 0.0;
	while (ft_isspace(*str))
		++str;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
		nb = nb * 10 + sign * (*str++ - '0');
	if (*str++ == '.')
	{
		i = 0;
		while (ft_isdigit(*str))
		{
			++i;
			fraction = (sign * (*str++ - '0')) / ft_pow(10, i);
			nb += fraction;
		}
	}
	return (nb);
}
