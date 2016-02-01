/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 09:42:29 by amanukya          #+#    #+#             */
/*   Updated: 2015/11/27 12:10:38 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		len;
	size_t		i;

	len = ft_strlen(s2);
	i = 0;
	if (!*s2)
		return ((char *)s1);
	while (s1[i] && i < n - len + 1)
	{
		if (ft_strncmp(s1 + i, s2, len) == 0)
			return ((char *)(s1 + i));
		i++;
	}
	return (NULL);
}
