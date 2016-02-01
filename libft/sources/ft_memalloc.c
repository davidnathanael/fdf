/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:39:54 by amanukya          #+#    #+#             */
/*   Updated: 2015/11/26 08:41:07 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*ret;
	size_t			i;

	ret = (void *)malloc(size);
	i = 0;
	if (!ret)
		return (NULL);
	while (i < size)
		ret[i++] = 0;
	return ((void *)ret);
}
