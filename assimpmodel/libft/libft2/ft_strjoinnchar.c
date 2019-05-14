/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinnchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 16:16:20 by edelangh          #+#    #+#             */
/*   Updated: 2015/01/07 18:23:53 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoinnchar2(char *s, int n, char c)
{
	char	*new;
	int		len;
	int		i;

	i = -1;
	if (n == 0)
		return (s);
	len = ft_strlen(s);
	if (!(new = (char*)malloc(len + n + 1)))
		return (NULL);
	new[len + n] = '\0';
	while (++i < len && s)
		new[i] = s[i];
	while (n--)
		new[n + i] = c;
	return (new);
}

char	*ft_strjoinnchar(char *s, int n, char c)
{
	char	*new;
	int		len;

	if (n < 0)
		return (ft_strjoinnchar2(s, -n, c));
	len = ft_strlen(s);
	if (!(new = (char*)malloc(len + n + 1)))
		return (NULL);
	new[len + n] = '\0';
	while (s && len--)
		new[len + n] = s[len];
	while (n--)
		new[n] = c;
	return (new);
}

char	*ft_strfjoinnchar(char *s, int n, char c)
{
	char	*new;

	new = ft_strjoinnchar(s, n, c);
	free(s);
	return (new);
}
