/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 15:28:47 by edelangh          #+#    #+#             */
/*   Updated: 2015/05/10 15:38:31 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(t_list *l)
{
	t_list	*n;

	n = NULL;
	while (l)
	{
		ft_lstpush(&n, ft_lstnew(l->content, l->content_size));
		l = l->next;
	}
	return (n);
}
