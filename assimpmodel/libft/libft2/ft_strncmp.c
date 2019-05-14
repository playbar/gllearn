/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:41:14 by edelangh          #+#    #+#             */
/*   Updated: 2016/03/22 18:28:06 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;

	i = -1;
	if (!s1 || !s2)
		return (s1 != s2);
	while (n--)
	{
		++i;
		if (s1[i] != s2[i])
			return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
	}
	return (0);
}
