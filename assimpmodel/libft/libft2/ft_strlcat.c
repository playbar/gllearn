/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:37:06 by edelangh          #+#    #+#             */
/*   Updated: 2014/11/10 12:07:25 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	int		i;
	int		n;
	size_t	k;

	k = 0;
	i = 0;
	len = ft_strlen(dst);
	n = size - len;
	while (--n > 0 && src[i])
	{
		dst[len + i] = src[i];
		++i;
	}
	while (k < len && k < size)
		++k;
	dst[i + len] = '\0';
	return (k + ft_strlen(src));
}
