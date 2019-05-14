/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 12:17:26 by edelangh          #+#    #+#             */
/*   Updated: 2015/01/30 14:13:52 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	size_t	len;
	size_t	i;
	char	swap;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	while (i != len / 2)
	{
		swap = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = swap;
		++i;
	}
	return (s);
}
