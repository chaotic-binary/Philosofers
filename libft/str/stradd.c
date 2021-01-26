/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stradd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 00:02:51 by ttamesha          #+#    #+#             */
/*   Updated: 2020/11/23 00:04:40 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		stradd(char **str, char *new)
{
	char *tmp;

	if (!new || !*str)
	{
		if (*str)
			free(*str);
		if (new)
			free(new);
		return (0);
	}
	tmp = *str;
	*str = ft_strjoin(tmp, new);
	free(tmp);
	free(new);
	if (!*str)
		return (0);
	return (1);
}
