/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:35:58 by edelangh          #+#    #+#             */
/*   Updated: 2015/06/05 17:23:25 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	int		len;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		++s;
	len = ft_strlen(s);
	while ((s[len] == ' ' || s[len] == '\n' || s[len] == '\t' || s[len] == '\0')
			&& len)
		--len;
	new = ft_strnew(len + 1);
	ft_strncpy(new, s, len + 1);
	new[len + 1] = '\0';
	return (new);
}
