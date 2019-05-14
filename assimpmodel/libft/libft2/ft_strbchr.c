/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelouni <nbelouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 21:42:40 by nbelouni          #+#    #+#             */
/*   Updated: 2016/03/23 15:03:49 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <stdlib.h>

char		*ft_strbchr(const char *s, int c)
{
	int		i;
	char	*new;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			break ;
		i++;
	}
	if (!(new = ft_strnew(i)))
		return (NULL);
	ft_strncpy(new, s, i);
	new[i] = '\0';
	return (new);
}
