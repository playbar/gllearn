/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/15 17:47:29 by edelangh          #+#    #+#             */
/*   Updated: 2015/01/20 15:38:16 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_atof(const char *str)
{
	double	result;
	int		i;

	result = (double)ft_atoi(str);
	i = ft_len_untill(str, '.');
	if (i)
	{
		if (result >= 0 && str[0] != '-')
			result += ((double)ft_atoi(str + i + 1))
				/ ((ft_strlen(str + i + 1) * 10));
		else
			result -= ((double)ft_atoi(str + i + 1))
				/ ((ft_strlen(str + i + 1) * 10));
	}
	return (result);
}
