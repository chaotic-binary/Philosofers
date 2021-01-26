/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:05:09 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/30 23:05:45 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** Like snprintf(3), the strlcpy() and strlcat() functions return the total
** length of the string they tried to create.  For strlcpy() that means the
** length of src.
*/

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	const char *s;

	s = src;
	if (size)
	{
		while (--size && *src)
			*dest++ = *src++;
		*dest = '\0';
	}
	while (*src)
		src++;
	return (src - s);
}
