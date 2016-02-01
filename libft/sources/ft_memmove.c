/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:06:06 by amanukya          #+#    #+#             */
/*   Updated: 2015/11/25 10:17:57 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*s1;
	const char	*s2;

	s1 = (char *)dst;
	s2 = (const char *)src;
	if (s2 <= s1)
	{
		s1 += len - 1;
		s2 += len - 1;
		while (len--)
			*s1-- = *s2--;
	}
	else
		while (len--)
			*s1++ = *s2++;
	return (dst);
}
