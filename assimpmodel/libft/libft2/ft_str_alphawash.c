/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_alphawash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 16:55:12 by edelangh          #+#    #+#             */
/*   Updated: 2015/01/13 18:07:02 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

size_t	ft_str_alphawash(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-')
			str[i] = ' ';
	}
	return (i);
}
