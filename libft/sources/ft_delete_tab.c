/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 12:44:02 by amanukya          #+#    #+#             */
/*   Updated: 2016/01/04 13:52:11 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tab_nb(char *str)
{
	int		n_tab;
	int		i;

	i = 0;
	n_tab = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			n_tab++;
		i++;
	}
	return (n_tab);
}

char	*ft_delete_tab(char *line)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = ft_strnew(ft_strlen(line) - ft_tab_nb(line) + 1);
	while (line[i])
	{
		if (line[i] != '\t')
		{
			new[j] = line[i];
			j++;
		}
		i++;
	}
	return (new);
}
