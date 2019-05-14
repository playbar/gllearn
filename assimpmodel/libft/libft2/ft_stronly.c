/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stronly.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 14:31:08 by edelangh          #+#    #+#             */
/*   Updated: 2015/05/08 18:27:09 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strisonly(char *str, char *only)
{
	int	i;
	int	j;

	i = -1;
	if (!str || !only)
		return (-1);
	while (str[++i])
	{
		j = 0;
		while (only[j] && only[j] != str[i])
			++j;
		if (only[j] != str[i])
			return (0);
	}
	return (1);
}

char	*ft_stronly(char *s, char *only)
{
	int	i;

	i = -1;
	if (!s || !only)
		return (NULL);
	while (s[++i])
	{
		if (ft_strchr(only, s[i]) == NULL)
		{
			ft_strcpy(s + i, s + i + 1);
			--i;
		}
	}
	return (s);
}
