/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:39:42 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/30 23:05:38 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		*ft_strdup(const char *src)
{
	char	*dub;

	dub = (char *)malloc(sizeof(*dub) * (ft_strlen(src) + 1));
	if (dub == NULL)
		return (NULL);
	return (ft_strcpy(dub, src));
}
