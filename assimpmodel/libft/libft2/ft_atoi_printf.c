/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/15 17:47:29 by edelangh          #+#    #+#             */
/*   Updated: 2015/01/08 10:46:58 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_atoi_printf(char *str)
{
	int		result;
	int		sign;
	int		i;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_isdigit(str[i]))
	{
		result = (result * 10) + (str[i] - '0');
		++i;
	}
	return (result * sign);
}
