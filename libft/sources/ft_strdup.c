/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:39:27 by amanukya          #+#    #+#             */
/*   Updated: 2015/11/27 11:58:59 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dest;

	dest = (char *)malloc(ft_strlen(str) + 1);
	if (dest == 0)
		return (NULL);
	return (ft_strcpy(dest, str));
}
