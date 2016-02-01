/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 20:25:49 by amanukya          #+#    #+#             */
/*   Updated: 2015/11/25 18:43:21 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*s1;
	const char	*s2;

	s1 = (char *)dst;
	s2 = (char *)src;
	while (n--)
	{
		*s1 = *s2;
		if (*s1 == c)
			return (s1 + 1);
		s1++;
		s2++;
	}
	return (NULL);
}
