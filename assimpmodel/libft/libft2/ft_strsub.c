/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:19:30 by edelangh          #+#    #+#             */
/*   Updated: 2014/11/12 10:45:16 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	new = ft_strnew(len);
	if (!new)
		return (NULL);
	while (s[start + i] && len)
	{
		--len;
		new[i] = s[start + i];
		++i;
	}
	return (new);
}
