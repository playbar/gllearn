/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 16:37:49 by edelangh          #+#    #+#             */
/*   Updated: 2016/03/25 11:00:17 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** res = s[i] + (res << 6) + (res << 16) - res; sdbm
** res = ((res << 5) + res) + s[i]; djb2
** res ^= (s[i] * 32) * i; prime
*/

int		hash(char *s, int max)
{
	int		i;
	int		res;

	if (!s)
		return (0);
	res = 0;
	i = -1;
	while (s[++i])
		res = s[i] + (res << 6) + (res << 16) - res;
	res %= max;
	if (res < 0)
		return (-res);
	return (res);
}
