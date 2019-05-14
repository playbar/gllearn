/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 15:29:48 by edelangh          #+#    #+#             */
/*   Updated: 2015/06/01 11:35:42 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_tabdup(char **tab)
{
	char	**cpy;
	size_t	size;
	int		i;

	if (!tab)
		return (NULL);
	size = ft_tablen(tab);
	cpy = ft_malloc((size + 1) * sizeof(char*));
	i = -1;
	while (tab[++i])
		cpy[i] = ft_strdup(tab[i]);
	cpy[i] = NULL;
	return (cpy);
}
