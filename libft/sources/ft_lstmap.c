/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 21:00:06 by amanukya          #+#    #+#             */
/*   Updated: 2015/11/27 09:19:21 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;
	t_list	*tmp;

	newlist = f(ft_lstnew(lst->content, lst->content_size));
	tmp = newlist;
	while (lst->next)
	{
		if (!lst->next)
			break ;
		lst = lst->next;
		tmp->next = f(lst);
		if (!tmp)
			return (NULL);
		tmp = tmp->next;
	}
	return (newlist);
}
