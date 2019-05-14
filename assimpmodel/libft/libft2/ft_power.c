/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 16:30:42 by edelangh          #+#    #+#             */
/*   Updated: 2015/01/12 18:33:26 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	ft_power(long double base, long double ex)
{
	long double half_pow;

	if (ex == 0)
		return (1);
	else if (ex < 0)
		return (1 / ft_power(base, -ex));
	else if ((int)ex % 2 == 0)
	{
		half_pow = ft_power(base, ex / 2);
		return (half_pow * half_pow);
	}
	else
		return (base * ft_power(base, ex - 1));
}
