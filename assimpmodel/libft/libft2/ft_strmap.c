/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:46:56 by edelangh          #+#    #+#             */
/*   Updated: 2014/11/12 10:40:45 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	int		i;
	char	*s2;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	s2 = ft_strnew(len);
	i = -1;
	while (s[++i])
		s2[i] = f(s[i]);
	s2[i] = '\0';
	return (s2);
}
