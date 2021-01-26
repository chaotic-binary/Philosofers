/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 00:30:35 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/30 23:06:00 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a copy of ’s1’
** with the characters specified in ’set’ removed
** from the beginning and the end of the string.
** Parameters
** #1. The string to be trimmed.
** #2. The reference set of characters to trim.
** RETURN The trimmed string. NULL if the allocation fails.
*/

#include "../libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	char const	*fin;
	char		*res;

	if (!s)
		return (NULL);
	while (ft_strchr(set, *s) && *s)
		s++;
	fin = s;
	while (*fin)
		fin++;
	while (ft_strchr(set, *fin) && (fin - s))
		fin--;
	res = ft_substr(s, 0, fin - s + 1);
	return (res);
}
