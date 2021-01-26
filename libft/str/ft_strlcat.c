/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:04:30 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/30 23:05:42 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** strlcat() appends string src to the end of dst.  It will append at
** most dstsize - strlen(dst) - 1 characters.  It will then NUL-termi-
** nate, unless dstsize is 0 or the original dst string was longer than
** dstsize (in practice this should not happen as it means that either
**dstsize is incorrect or that dst is not a proper string).
**Like snprintf(3), the strlcpy() and strlcat() functions return the
**total length of the string they tried to create.
**For strlcat() that means the initial length
**of dst plus the length of src.
*/

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		len;

	d = dst;
	s = src;
	while (size && *dst)
	{
		dst++;
		size--;
	}
	len = dst - d;
	if (size == 0)
		return (len + ft_strlen(src));
	while (size - 1 && *src)
	{
		size--;
		*dst++ = *src++;
	}
	*dst = '\0';
	while (*src)
		src++;
	return (src - s + len);
}
