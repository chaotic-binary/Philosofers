/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 00:46:52 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/30 23:06:02 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a substring from the string ’s’.
** The substring begins at index ’start’ and is of maximum size ’len’.
** Parameters
** #1. The string from which to create the substring.
** #2. The start index of the substring in the string ’s’.
** #3. The maximum length of the substring.
** RETURN The substring. NULL if the allocation fails.
*/

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rptr;
	char	*szero;
	char	*rzero;

	if (!s)
		return (NULL);
	szero = (char*)s;
	while (s - szero < start && *s)
		s++;
	szero = (char*)s;
	while (*s && len--)
		s++;
	rzero = (char *)malloc(sizeof(char) * (s - szero + 1));
	if (rzero == NULL)
		return (NULL);
	rptr = rzero;
	while (s - szero && *szero)
		*rptr++ = *szero++;
	*rptr = '\0';
	return (rzero);
}
