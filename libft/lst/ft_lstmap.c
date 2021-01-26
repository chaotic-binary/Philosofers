/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 20:19:15 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/30 23:04:08 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_lstadd_back_mod(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while ((*lst)->next)
		(*lst) = (*lst)->next;
	(*lst)->next = new;
}

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *elem;
	t_list *start;
	t_list *last;

	if (!f || !del || !lst)
		return (NULL);
	start = ft_lstnew(f(lst->content));
	if (!start)
	{
		ft_lstclear(&start, del);
		return (NULL);
	}
	last = start;
	while (lst->next)
	{
		lst = lst->next;
		elem = ft_lstnew(f(lst->content));
		if (!elem)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		ft_lstadd_back_mod(&last, elem);
	}
	return (start);
}
