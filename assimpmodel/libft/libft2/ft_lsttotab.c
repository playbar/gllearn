/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttotab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 17:14:56 by edelangh          #+#    #+#             */
/*   Updated: 2016/07/26 14:28:17 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_lsttotab(t_list *lst, void *(*dup_content)(void*, size_t))
{
	void	**tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(void*) * (ft_lstlen(lst) + 1));
	while (lst)
	{
		tab[i++] = dup_content(lst->content, lst->content_size);
		lst = lst->next;
	}
	tab[i] = NULL;
	return (tab);
}
