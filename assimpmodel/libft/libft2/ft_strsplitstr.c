/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 17:06:37 by edelangh          #+#    #+#             */
/*   Updated: 2015/02/05 17:12:30 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplitstr(char *s, char *c)
{
	char	*splitable;
	char	**tab;

	tab = NULL;
	splitable = ft_strfreplace(ft_strdup(s), c, "\177");
	if (splitable)
	{
		tab = ft_strsplit(splitable, '\177');
		ft_free(splitable);
	}
	return (tab);
}
