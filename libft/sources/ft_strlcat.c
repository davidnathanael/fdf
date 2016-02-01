/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 08:46:51 by amanukya          #+#    #+#             */
/*   Updated: 2015/11/27 12:06:46 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*strdest;
	const char	*strsrc;
	size_t		n;
	size_t		len;

	strdest = dst;
	strsrc = src;
	n = size;
	while (*strdest != '\0' && n-- != 0)
		strdest++;
	len = strdest - dst;
	n = size - len;
	if (n == 0)
		return (len + ft_strlen(strsrc));
	while (*strsrc != '\0')
	{
		if (n != 1)
		{
			*strdest++ = *strsrc;
			n--;
		}
		strsrc++;
	}
	*strdest = '\0';
	return (len + (strsrc - src));
}
