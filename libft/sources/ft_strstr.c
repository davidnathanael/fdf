/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 09:27:08 by amanukya          #+#    #+#             */
/*   Updated: 2015/11/25 16:04:13 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		len;

	len = ft_strlen(s2);
	if (!*s2)
		return ((char *)s1);
	while (*s1)
	{
		if (ft_strncmp(s1, s2, len) == 0)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
