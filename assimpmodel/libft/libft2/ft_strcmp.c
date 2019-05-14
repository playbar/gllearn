/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:42:36 by edelangh          #+#    #+#             */
/*   Updated: 2015/05/20 11:48:07 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (s1 != s2);
	while (s1[i] == s2[i] && s1[i])
		++i;
	return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
}
