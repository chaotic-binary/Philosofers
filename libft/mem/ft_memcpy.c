/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:57:35 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/30 23:04:37 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The memcpy() function copies n bytes
** from memory area src to memory area dest.
** If dest and src overlap, behavior is undefined.
** Returns a pointer to destination
*/

#include "../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *d;

	d = (unsigned char *)dest;
	if (n == 0 || dest == src)
		return (dest);
	while (n--)
		*d++ = *((unsigned char *)src++);
	return (dest);
}
