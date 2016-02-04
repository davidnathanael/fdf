/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adomingu <adomingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 06:36:28 by adomingu          #+#    #+#             */
/*   Updated: 2016/01/15 16:01:25 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa_base(unsigned long long n, char *base)
{
	char				*s;
	unsigned long long	i;

	i = ft_strlen(base);
	s = (char *)malloc(sizeof(char) * 2);
	if (!s)
		return (NULL);
	if (n >= i)
		s = ft_strjoin(ft_itoa_base(n / i, base), ft_itoa_base(n % i, base));
	else if (n < i)
	{
		s[0] = base[n];
		s[1] = '\0';
	}
	return (s);
}
