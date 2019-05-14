/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:45:54 by edelangh          #+#    #+#             */
/*   Updated: 2015/06/07 19:13:16 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + 1;
	s2 = (char*)malloc((len) * sizeof(char));
	ft_memcpy(s2, s1, len);
	return (s2);
}
