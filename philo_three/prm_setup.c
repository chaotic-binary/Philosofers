/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prm_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 20:04:32 by ttamesha          #+#    #+#             */
/*   Updated: 2021/01/27 20:19:32 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

static int	ft_max(int x, int y)
{
	return ((x > y) ? x : y);
}

static int	ft_atoi(char *str)
{
	long		nb;
	int			sign;

	nb = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + sign * (*str++ - '0');
		if ((nb != 0) && ((nb > 0) != (sign > 0)))
			return (sign == 1 ? -1 : 0);
	}
	return ((int)nb);
}

static int	is_uint(char *w)
{
	int i;

	i = -1;
	if (w[0] == '-')
	{
		write(2, "Negative values not allowed\n", 28);
		return (0);
	}
	if (w[0] == '+')
		++i;
	while (w[++i])
	{
		if (!ft_isdigit(w[i]))
		{
			write(2, "Bad arguments\n", 14);
			return (0);
		}
	}
	return (1);
}

int			prm_setup(int ac, char **av, t_prm *prm, t_ctrl *ctrl)
{
	if (ac != 5 && ac != 6)
	{
		write(2, "Wrong number of arguments\n", 26);
		return (0);
	}
	if (!(is_uint(av[1]) && is_uint(av[2]) && is_uint(av[3])\
		&& is_uint(av[4]) && (!av[5] || is_uint(av[5]))))
		return (0);
	prm->num = ft_atoi(av[1]);
	prm->die = ft_atoi(av[2]);
	prm->eat = ft_atoi(av[3]);
	prm->sleep = ft_atoi(av[4]);
	prm->delay = (ft_max(prm->eat, prm->sleep) + 10) * 1000;
	prm->meals = (ac == 6) ? ft_atoi(av[5]) : INT_MAX;
	if (prm->num < 2 || prm->die < 0 || prm->eat < 0 \
			|| prm->meals < 0 || prm->sleep < 0)
	{
		write(2, "Bad arguments\n", 14);
		return (0);
	}
	prm->fed = 0;
	ctrl->prm = prm;
	ctrl->ph = NULL;
	return (1);
}
