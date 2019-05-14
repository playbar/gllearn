/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:32:49 by edelangh          #+#    #+#             */
/*   Updated: 2014/11/27 11:52:13 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int					a;
	unsigned char		*b;
	const unsigned char	*c;

	if (!dst || !src)
		return (NULL);
	a = 0;
	b = (unsigned char*)dst;
	c = (const unsigned char*)src;
	while (n--)
	{
		b[a] = c[a];
		++a;
	}
	return (dst);
}
