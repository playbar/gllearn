/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:03:58 by edelangh          #+#    #+#             */
/*   Updated: 2014/11/04 17:40:07 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				a;
	unsigned char	*str;

	str = (unsigned char*)b;
	a = 0;
	while (len--)
		str[a++] = (unsigned char)c;
	return (b);
}
