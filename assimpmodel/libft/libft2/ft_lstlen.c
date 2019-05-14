/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 16:42:23 by edelangh          #+#    #+#             */
/*   Updated: 2014/11/22 17:47:59 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstlen(t_list *lst)
{
	size_t len;

	len = 0;
	while (lst)
	{
		++len;
		lst = lst->next;
	}
	return (len);
}
