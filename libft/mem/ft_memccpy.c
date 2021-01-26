/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:29:53 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/30 23:04:30 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**The memccpy() function copies bytes from src to dest,
** up to and including the first occurrence of the character c,
**or until n bytes have been copied, whichever comes first.
**Returns:
**A pointer to the byte in dest following the character c,
** if one is found and copied;
**otherwise, NULL.
*/

#include "../libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*d;

	d = (unsigned char *)dest;
	while (n--)
	{
		*d = *(unsigned char *)src;
		if (*d == (unsigned char)c)
			return (d + 1);
		d++;
		src++;
	}
	return (NULL);
}
