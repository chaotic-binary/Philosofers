/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 17:59:37 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/30 23:04:44 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*malloc_c(size_t size)
{
	static void	*collection[1024];
	static int	p;
	int			i;

	if (size)
		collection[p] = malloc(size);
	if (!size || !collection[p])
	{
		i = 0;
		while (i < p - 1)
		{
			if (collection[i])
				free(collection[i]);
			++i;
		}
		return (NULL);
	}
	return (collection[p++]);
}
