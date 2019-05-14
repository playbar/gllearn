/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmergesort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 12:58:13 by edelangh          #+#    #+#             */
/*   Updated: 2015/02/01 12:45:04 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_sort_merge(t_list *a, t_list *b, int (*f)(void*, void*))
{
	t_list	*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (f(a->content, b->content) <= 0)
	{
		result = a;
		result->next = ft_sort_merge(a->next, b, f);
	}
	else
	{
		result = b;
		result->next = ft_sort_merge(a, b->next, f);
	}
	return (result);
}

static void	ft_lst_split(t_list *source, t_list **afront, t_list **aback)
{
	t_list	*fast;
	t_list	*slow;

	if (source == NULL || source->next == NULL)
	{
		*afront = source;
		*aback = NULL;
	}
	else
	{
		slow = source;
		fast = source->next;
		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		*afront = source;
		*aback = slow->next;
		slow->next = NULL;
	}
}

void		ft_lstmergesort(t_list **alst, int (*f)(void*, void*))
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = *alst;
	(void)f;
	if ((head == NULL) || (head->next == NULL))
		return ;
	ft_lst_split(head, &a, &b);
	ft_lstmergesort(&a, f);
	ft_lstmergesort(&b, f);
	*alst = ft_sort_merge(a, b, f);
}
