/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 12:45:53 by edelangh          #+#    #+#             */
/*   Updated: 2015/06/01 12:53:23 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_tabjoin(char **tab, char *c)
{
	char	*res;
	size_t	len;
	int		i;

	if (!tab || !tab[0] || !c)
		return (NULL);
	i = 0;
	len = 0;
	while (tab[i])
	{
		len += ft_strlen(tab[i]);
		++i;
	}
	if (!(res = malloc(len + 1 + ft_strlen(c) * i)))
		return (res);
	res[0] = '\0';
	i = 0;
	while (tab[i])
	{
		ft_strcat(res, tab[i]);
		ft_strcat(res, c);
		++i;
	}
	return (res);
}
