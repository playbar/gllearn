/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:49:35 by edelangh          #+#    #+#             */
/*   Updated: 2015/01/30 13:21:13 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*t1;
	char	*t2;
	char	*t3;

	t1 = (char*)s1;
	if (!s1 || !s2)
		return (NULL);
	while (*t1)
	{
		t3 = t1;
		t2 = (char*)s2;
		while (*t2 && *t2 == *t3)
		{
			++t2;
			++t3;
		}
		++t1;
		if (*t2 == '\0')
			return (t1 - 1);
	}
	if (!*s1 && !*s2)
		return (t1);
	return (NULL);
}
