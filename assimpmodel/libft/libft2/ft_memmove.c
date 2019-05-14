/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:26:32 by edelangh          #+#    #+#             */
/*   Updated: 2014/11/05 15:32:05 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				i;
	unsigned char	*s1;
	unsigned char	*s2;

	s2 = (unsigned char*)dst;
	s1 = (unsigned char*)src;
	if (s1 > s2)
	{
		i = 0;
		while (i <= (int)len - 1)
		{
			s2[i] = s1[i];
			++i;
		}
	}
	else if (s1 < s2)
	{
		i = len - 1;
		while (i >= 0)
		{
			s2[i] = s1[i];
			--i;
		}
	}
	return (dst);
}
