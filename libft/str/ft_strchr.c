/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 20:52:03 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/30 23:05:32 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str != (char)c)
			str++;
		else
			return ((char *)str);
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}
