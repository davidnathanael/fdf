/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:14:59 by amanukya          #+#    #+#             */
/*   Updated: 2015/11/27 11:29:46 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_convert(char *str, int tmp, int len)
{
	int i;

	i = 0;
	if (tmp < 0)
	{
		str[i++] = '-';
		tmp = -tmp;
	}
	while (len)
	{
		str[i++] = (tmp / len) + '0';
		tmp %= len;
		len /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		tmp;

	tmp = n;
	len = 1;
	str = (char *)malloc(12);
	if (!str)
		return (NULL);
	if (n == 0)
		return ("0");
	if (n == -2147483648)
		return ("-2147483648");
	while (n /= 10)
		len *= 10;
	return (ft_convert(str, tmp, len));
}
