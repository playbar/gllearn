/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:37:41 by edelangh          #+#    #+#             */
/*   Updated: 2016/03/22 17:48:38 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s1;

	s1 = (char*)s;
	if (s)
	{
		while (*s1)
		{
			if ((*s1) == (char)c)
				return (s1);
			++s1;
		}
		if ((*s1) == (char)c)
			return (s1);
	}
	return (NULL);
}
