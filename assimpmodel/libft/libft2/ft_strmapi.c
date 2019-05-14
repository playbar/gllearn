/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:10:58 by edelangh          #+#    #+#             */
/*   Updated: 2014/11/10 12:56:54 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s2;

	if (!s || !f)
		return (NULL);
	s2 = ft_memalloc(ft_strlen(s) + 1);
	i = 0;
	while (s[i])
	{
		s2[i] = (*f)(i, s[i]);
		++i;
	}
	return (s2);
}
