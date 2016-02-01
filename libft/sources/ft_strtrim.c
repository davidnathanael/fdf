/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:08:16 by amanukya          #+#    #+#             */
/*   Updated: 2015/11/25 20:35:52 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = ft_strlen(s) - 1;
	if (!*s)
		return ("");
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i < j)
		i++;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && j >= i)
		j--;
	return (ft_strsub(s, i, j - i + 1));
}
