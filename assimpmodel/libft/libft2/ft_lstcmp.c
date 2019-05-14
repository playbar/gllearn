/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 15:48:03 by edelangh          #+#    #+#             */
/*   Updated: 2016/03/25 11:38:45 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		int_cmp(void *a, void *b)
{
	int	c;
	int	d;

	c = *(int*)a;
	d = *(int*)b;
	return (c - d);
}

int		ft_lstcmp(t_list *a, t_list *b, int (*cmp)(void*, void*))
{
	int	i;
	int	diff;

	diff = 0;
	i = -1;
	while (a && b)
	{
		++i;
		if (cmp(a->content, b->content))
		{
			diff++;
		}
		a = a->next;
		b = b->next;
	}
	diff += FT_ABS((int)ft_lstlen(a) - (int)ft_lstlen(b));
	return (diff);
}
