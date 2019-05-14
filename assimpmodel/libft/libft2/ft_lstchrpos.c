/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstchrpos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 15:40:25 by edelangh          #+#    #+#             */
/*   Updated: 2015/06/07 15:14:40 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** cmp, norm C, return 0 if is equal
** ft_lstchrpos return -1 if not found
*/

int		ft_lstchrpos(t_list *l, void *a, int (*cmp)(void *, void *))
{
	int	i;

	if (!l)
		return (-1);
	i = -1;
	while (l)
	{
		++i;
		if (cmp(l->content, a) == 0)
			return (i);
		l = l->next;
	}
	return (-1);
}
