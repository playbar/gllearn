/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnreplace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 15:40:23 by edelangh          #+#    #+#             */
/*   Updated: 2016/10/18 17:11:11 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strfnreplace(char *str, char *match, char *to, size_t nbr)
{
	size_t	pos;
	int		len;
	char	*last;
	char	*tmp;

	last = NULL;
	if (!str || !ft_strlen(match) || !to)
		return (str);
	while (str != last && (last = str) && nbr--)
	{
		if ((tmp = ft_strstr(str, match)))
		{
			pos = (size_t)(tmp - str);
			if (pos < ft_strlen(str))
			{
				len = ft_strlen(match);
				ft_memmove(str + pos, str + pos + len,
						ft_strlen(str + pos + len) + 1);
				str = ft_strfinsert(str, to, pos, 1);
			}
		}
	}
	return (str);
}

char	*ft_strnreplace(char *str, char *match, char *to, size_t nbr)
{
	size_t	pos;
	int		len;
	char	*last;
	char	*tmp;

	last = NULL;
	if (!str || !ft_strlen(match) || !to)
		return (str);
	while (str != last && (last = str) && nbr--)
	{
		if ((tmp = ft_strstr(str, match)))
		{
			pos = (size_t)(tmp - str);
			if (pos < ft_strlen(str))
			{
				len = ft_strlen(match);
				ft_memmove(str + pos, str + pos + len,
						ft_strlen(str + pos + len) + 1);
				str = ft_strinsert(str, to, pos);
			}
		}
	}
	return (str);
}

char	*ft_strfreplace(char *str, char *match, char *to)
{
	size_t	pos;
	int		len;
	char	*last;
	char	*tmp;

	last = NULL;
	if (!str || !ft_strlen(match) || !to)
		return (str);
	while (str != last && (last = str))
	{
		if ((tmp = ft_strstr(str, match)))
		{
			pos = (size_t)(tmp - str);
			if (pos < ft_strlen(str))
			{
				len = ft_strlen(match);
				ft_memmove(str + pos, str + pos + len,
						ft_strlen(str + pos + len) + 1);
				str = ft_strfinsert(str, to, pos, 1);
			}
		}
	}
	return (str);
}

char	*ft_strreplace(char *str, char *match, char *to)
{
	size_t	pos;
	int		len;
	char	*last;
	char	*tmp;

	last = NULL;
	if (!str || !ft_strlen(match) || !to)
		return (NULL);
	str = ft_strdup(str);
	while (str != last && (last = str))
	{
		if ((tmp = ft_strstr(str, match)))
		{
			pos = (size_t)(tmp - str);
			if (pos < ft_strlen(str))
			{
				len = ft_strlen(match);
				ft_memmove(str + pos, str + pos + len,
						ft_strlen(str + pos + len) + 1);
				str = ft_strfinsert(str, to, pos, 1);
			}
		}
	}
	return (str);
}
