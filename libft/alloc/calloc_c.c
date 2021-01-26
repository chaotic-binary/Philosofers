/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 20:50:03 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/30 23:04:20 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*calloc_c(size_t nitems, size_t size)
{
	void *new;

	if (nitems && ((size * nitems) / nitems) != size)
		return (NULL);
	size *= nitems;
	new = (void *)malloc_c(size);
	if (new)
		ft_bzero(new, size);
	return (new);
}
