/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:54:43 by edelangh          #+#    #+#             */
/*   Updated: 2014/11/11 11:22:31 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*s1;
	unsigned const char	*s2;
	int					i;

	s1 = (unsigned char*)dst;
	s2 = (unsigned const char*)src;
	i = 0;
	while (n--)
	{
		s1[i] = s2[i];
		if (s2[i++] == (unsigned char)c)
			return (dst + i);
	}
	return (NULL);
}
