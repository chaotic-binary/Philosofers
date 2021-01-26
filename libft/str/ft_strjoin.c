/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 22:41:17 by ttamesha          #+#    #+#             */
/*   Updated: 2021/01/07 16:35:50 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a new string,
** which is the result of the concatenation of ’s1’ and ’s2’.
** Parameters
** #1. The prefix string.
** #2. The suffix string.
** RETURN The new string. NULL if the allocation fails.
*/

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	char	*newptr;

	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new == NULL)
		return (NULL);
	newptr = new;
	while (*s1)
		*newptr++ = *s1++;
	while (*s2)
		*newptr++ = *s2++;
	*newptr = '\0';
	return (new);
}
