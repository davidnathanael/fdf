/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:23:17 by amanukya          #+#    #+#             */
/*   Updated: 2015/11/26 09:21:21 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*tmpnext;

	tmp = *alst;
	while (tmp != NULL)
	{
		tmpnext = tmp->next;
		del(tmp->content, tmp->content_size);
		free(tmp);
		tmp = tmpnext;
	}
	*alst = NULL;
}
