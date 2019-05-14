/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/15 17:47:29 by edelangh          #+#    #+#             */
/*   Updated: 2014/11/10 11:16:48 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		result;
	int		sign;
	int		i;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\r' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f')
		++i;
	if (str[i] == '-')
	{
		sign = -1;
		++i;
	}
	else if (str[i] == '+')
		++i;
	while (ft_isdigit(str[i]))
	{
		result = (result * 10) + (str[i] - '0');
		++i;
	}
	return (result * sign);
}
