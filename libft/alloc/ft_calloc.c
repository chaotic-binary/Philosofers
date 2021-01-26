/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:12:58 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/30 23:04:27 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void *new;

	if (nitems && ((size * nitems) / nitems) != size)
		return (NULL);
	size *= nitems;
	new = (void *)malloc(size);
	if (new == NULL)
		return (NULL);
	ft_bzero(new, size);
	return (new);
}
