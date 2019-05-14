/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:31:19 by edelangh          #+#    #+#             */
/*   Updated: 2014/11/25 14:55:32 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_free2(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
}

char		*ft_strfjoin(char *str1, char *str2, int a, int b)
{
	char	*s1;
	char	*s2;
	char	*s3;
	int		len;
	int		i;

	s1 = str1;
	s2 = str2;
	s3 = NULL;
	if (!s2 && s1)
		s3 = ft_strdup(s1);
	else if (!s1 && s2)
		s3 = ft_strdup(s2);
	else if (s1 && s2 && !(i = 0))
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		s3 = ft_strnew(len);
		while (*s1)
			s3[i++] = *(s1++);
		while (*s2)
			s3[i++] = *(s2++);
		s3[i] = '\0';
	}
	ft_free2((a > 0 ? str1 : NULL), (b > 0 ? str2 : NULL));
	return (s3);
}
