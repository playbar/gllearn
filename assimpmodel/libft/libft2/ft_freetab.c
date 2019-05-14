/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 15:26:29 by edelangh          #+#    #+#             */
/*   Updated: 2015/01/26 15:28:15 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_freetab(char **tab)
{
	int		i;

	if (!tab)
		return (0);
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (0);
}
