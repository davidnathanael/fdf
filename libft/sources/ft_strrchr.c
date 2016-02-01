/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 09:18:57 by amanukya          #+#    #+#             */
/*   Updated: 2015/11/26 09:01:44 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	int		find;

	find = 0;
	while (*s)
	{
		if (*s == c)
		{
			tmp = (char *)s;
			find = 1;
		}
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	if (!find)
		return (NULL);
	return (tmp);
}
