/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 10:54:32 by edelangh          #+#    #+#             */
/*   Updated: 2014/11/25 14:49:34 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*save;

	if (!lst || !f)
		return (NULL);
	new = NULL;
	while (lst)
	{
		save = ft_lstnew(lst->content, lst->content_size);
		save = f(save);
		if (!new)
			new = save;
		else
			ft_lstend(new)->next = save;
		lst = lst->next;
		save = save->next;
	}
	return (new);
}
