/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 00:37:46 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/30 23:05:29 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns an array of strings
** obtained by splitting ’s’ using the character ’c’ as a delimiter.
** The array must be ended by a NULL pointer.
** #1. The string to be split.
** #2. The delimiter character.
** RETURN The array of new strings resulting from the split.
** NULL if the allocation fails.
*/

#include "../libft.h"

static size_t	wcount(char const *s, char c)
{
	size_t	wc;

	wc = 0;
	while (*s)
	{
		if ((*(s + 1) == c || *(s + 1) == '\0') && (*s != c))
			wc++;
		s++;
	}
	return (wc);
}

static int		fill_arr(char **arr, char const *s, char c)
{
	char const		*start;
	size_t			i;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		start = s;
		while (*s != c && *s)
		{
			if (*(s + 1) == c || *(s + 1) == '\0')
			{
				if (!(*(arr + i) = ft_substr(start, 0, s + 1 - start)))
				{
					free_arr(arr);
					return (-1);
				}
				i++;
			}
			s++;
		}
	}
	*(arr + i) = NULL;
	return (1);
}

char			**ft_split(char const *s, char c)
{
	char	**res;
	size_t	wc;

	if (!s)
		return (NULL);
	wc = wcount(s, c) + 1;
	res = (char **)malloc(sizeof(char *) * wc);
	if (!res)
		return (NULL);
	if (fill_arr(res, s, c) == -1)
		return (NULL);
	return (res);
}
