/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:31:19 by edelangh          #+#    #+#             */
/*   Updated: 2014/11/12 10:45:04 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		len;
	int		i;

	if (!s2 && s1)
		return (ft_strdup(s1));
	else if (!s1 && s2)
		return (ft_strdup(s2));
	else if (!s1 && !s2)
		return (NULL);
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	s3 = ft_strnew(len);
	while (*s1)
		s3[i++] = *(s1++);
	while (*s2)
	{
		s3[i] = *s2;
		++s2;
		++i;
	}
	s3[i] = '\0';
	return (s3);
}
