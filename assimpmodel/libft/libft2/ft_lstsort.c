/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 10:30:25 by edelangh          #+#    #+#             */
/*   Updated: 2014/11/22 14:53:34 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list *lst, int (*f)(void*, void*))
{
	t_list	*tmp;
	int		flag;
	void	*swap;

	flag = 1;
	if (!lst || !f)
		return ;
	if (!lst->next)
		return ;
	while (flag)
	{
		tmp = lst;
		flag = 0;
		while (tmp->next)
		{
			if (f(tmp->content, tmp->next->content) > 0)
			{
				swap = tmp->content;
				tmp->content = tmp->next->content;
				tmp->next->content = swap;
				flag = 1;
			}
			tmp = tmp->next;
		}
	}
}
