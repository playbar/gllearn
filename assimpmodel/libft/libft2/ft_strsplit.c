/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/11 16:48:56 by edelangh          #+#    #+#             */
/*   Updated: 2014/11/10 18:54:59 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_split_len(const char *str, char c)
{
	int		len;

	len = 1;
	while (str)
	{
		str = ft_strchr(str, c);
		while (str && *str == c)
			++str;
		if (!str)
			return (len);
		if (!*str)
			return (len);
		++len;
	}
	return (len);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		len;
	char	*tmp;
	char	**save;

	if (!s)
		return (NULL);
	while (*s == c)
		++s;
	if (!*s)
		return (ft_memalloc(sizeof(char*)));
	len = ft_split_len(s, c) + 1;
	tab = (char**)ft_memalloc(len * sizeof(char*));
	save = tab;
	while (--len)
	{
		tmp = ft_strchr(s, c);
		if (!tmp && (*(tab++) = ft_strdup(s)))
			break ;
		*(tab++) = ft_strsub(s, 0, tmp - s);
		while (*tmp == c)
			++tmp;
		s = tmp;
	}
	return (save);
}
