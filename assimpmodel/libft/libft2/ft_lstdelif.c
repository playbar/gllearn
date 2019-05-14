/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 18:32:17 by edelangh          #+#    #+#             */
/*   Updated: 2016/03/25 11:37:33 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstdelif(t_list **alst, void *ref, int (*f)(void*, void*))
{
	t_list	*lst;
	t_list	*prev;

	if (!alst || !*alst)
		return (0);
	prev = NULL;
	lst = *alst;
	while (lst)
	{
		if (!f(lst->content, ref))
		{
			if (prev)
				prev->next = lst->next;
			else
				*alst = lst->next;
			lst = lst->next;
		}
		else
		{
			prev = lst;
			lst = lst->next;
		}
	}
	return (0);
}
