/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 21:13:04 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/30 23:05:58 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *res;

	res = 0;
	while (*str)
	{
		if (*str == (char)c)
			res = ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (res);
}
