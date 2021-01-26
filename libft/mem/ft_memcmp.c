/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 00:07:54 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/30 23:04:34 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Compares the first n bytes of memory area str1 and memory area str2
** if Return value < 0 then it indicates str1 is less than str2.
** if Return value > 0 then it indicates str2 is less than str1.
** if Return value = 0 then it indicates str1 is equal to str2.
*/

#include "../libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	if (n == 0)
		return (0);
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	i = 0;
	while (s1[i] == s2[i] && i < (n - 1))
		i++;
	return (s1[i] - s2[i]);
}
