/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 16:12:41 by edelangh          #+#    #+#             */
/*   Updated: 2015/05/10 17:51:24 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstr(t_list **al)
{
	t_list *l;
	t_list *first;

	if (!al || !*al)
		return (NULL);
	l = *al;
	if (l->next)
	{
		*al = l->next;
		first = l;
		l = l->next;
		while (l->next)
			l = l->next;
		l->next = first;
		first->next = NULL;
	}
	return (*al);
}

t_list	*ft_lstrr(t_list **al)
{
	t_list *l;
	t_list *prev;

	if (!al || !*al)
		return (NULL);
	l = *al;
	if (l->next)
	{
		while ((*al)->next)
		{
			prev = *al;
			*al = (*al)->next;
		}
		(*al)->next = l;
		prev->next = NULL;
	}
	return (*al);
}
