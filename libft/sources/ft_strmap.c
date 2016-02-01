/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:27:41 by amanukya          #+#    #+#             */
/*   Updated: 2015/11/25 19:58:35 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strdup(s);
	while (s[i])
	{
		str[i] = f(s[i]);
		i++;
	}
	return (str);
}
