/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rsqrt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 14:07:42 by edelangh          #+#    #+#             */
/*   Updated: 2015/01/22 14:23:19 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_rsqrt(float number)
{
	long			i;
	float			x2;
	float			y;
	const float		threehalfs = 1.5F;

	x2 = number * 0.5F;
	y = number;
	i = *(long*)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float*)&i;
	y = y * (threehalfs - (x2 * y * y));
	y = y * (threehalfs - (x2 * y * y));
	return (y);
}
