/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 21:30:50 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/30 23:05:55 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *hst, const char *ndl, size_t n)
{
	unsigned int i;
	unsigned int p;

	if (ndl[0] == '\0')
		return ((char *)hst);
	p = 0;
	while (hst[p] && p < n)
	{
		if (hst[p] == ndl[0])
		{
			i = 1;
			while (hst[p + i] == ndl[i] && ndl[i] && p + i < n)
				i++;
			if (ndl[i] == '\0')
				return ((char *)&hst[p]);
		}
		p++;
	}
	return (NULL);
}
