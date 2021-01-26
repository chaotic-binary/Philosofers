/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 23:02:33 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/30 23:04:39 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (n == 0 || dest == src)
		return (dest);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	if (dest > src)
	{
		while (n--)
			*(d + n) = *(s + n);
	}
	return (dest);
}
