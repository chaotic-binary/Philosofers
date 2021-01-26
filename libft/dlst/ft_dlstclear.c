/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 18:45:46 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/30 23:03:08 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_dlstclear(t_dlist **lst, void (*del)(void *))
{
	t_dlist *tmp;
	t_dlist *lptr;

	if (!del || !lst || !*lst)
		return ;
	lptr = *lst;
	while (lptr)
	{
		tmp = lptr->next;
		del(lptr->content);
		free(lptr);
		lptr = tmp;
	}
	*lst = NULL;
}
