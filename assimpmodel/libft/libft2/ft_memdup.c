/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:45:54 by edelangh          #+#    #+#             */
/*   Updated: 2014/11/25 14:52:50 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memdup(const void *s1, size_t len)
{
	char	*s2;

	s2 = (char*)ft_malloc((len) * sizeof(char));
	ft_memcpy(s2, s1, len);
	return (s2);
}
