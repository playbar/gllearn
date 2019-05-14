/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:06:27 by edelangh          #+#    #+#             */
/*   Updated: 2014/11/12 10:36:30 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*t1;
	char	*t2;
	char	*t3;
	size_t	len;

	t1 = (char*)s1;
	len = ft_strlen(s2);
	while (*t1 && n-- >= len)
	{
		t3 = t1;
		t2 = (char*)s2;
		while (*t2 && *t2 == *t3)
		{
			++t2;
			++t3;
		}
		if (*t2 == '\0')
			return (t1);
		++t1;
	}
	if (!*s1 && !*s2)
		return (t1);
	return (NULL);
}
