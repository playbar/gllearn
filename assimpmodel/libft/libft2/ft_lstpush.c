/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 12:19:00 by edelangh          #+#    #+#             */
/*   Updated: 2014/11/29 12:24:05 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpush(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = NULL;
	if (lst)
		tmp = ft_lstend(*lst);
	if (tmp)
	{
		tmp->next = new;
		return (*lst);
	}
	else if (lst)
	{
		*lst = new;
		return (*lst);
	}
	return (new);
}
