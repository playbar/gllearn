/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 18:12:31 by edelangh          #+#    #+#             */
/*   Updated: 2015/01/07 18:17:25 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strinsert(char *a, char *b, int pos)
{
	char *s1;
	char *s2;

	s1 = ft_strsub(a, 0, pos);
	s2 = ft_strsub(a, pos, ft_strlen(a));
	s1 = ft_strfjoin(s1, b, 1, 0);
	s1 = ft_strfjoin(s1, s2, 1, 1);
	return (s1);
}

char	*ft_strfinsert(char *a, char *b, int pos, int frees)
{
	char *s1;
	char *s2;

	s1 = ft_strsub(a, 0, pos);
	s2 = ft_strsub(a, pos, ft_strlen(a));
	s1 = ft_strfjoin(s1, b, 1, 0);
	s1 = ft_strfjoin(s1, s2, 1, 1);
	if (frees == 1 || frees == 3)
		free(a);
	if (frees == 2 || frees == 3)
		free(b);
	return (s1);
}
