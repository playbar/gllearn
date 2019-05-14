/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 12:12:28 by edelangh          #+#    #+#             */
/*   Updated: 2015/01/08 10:47:28 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_ftohex2(char *s, double f)
{
	int	len_max;
	int	i;

	i = 0;
	len_max = 14;
	f = f - (double)(int)f;
	while (f && --len_max)
	{
		f = f * 16.0;
		s[i++] = "0123456789abcdef"[(int)f];
		f = f - (double)(int)f;
	}
	return (i);
}

static int		ft_init_hex(char *s)
{
	*(s++) = '0';
	*(s++) = 'x';
	*(s++) = '1';
	*(s++) = '.';
	return (4);
}

char			*ft_ftohex(long double f)
{
	char		*s;
	int			i;
	long double	res;
	int			x;
	int			sign;

	if ((x = -1) && f == 0.0)
		return (ft_strdup("0x0p+0"));
	i = 0;
	s = ft_strnew(20);
	if ((sign = (f < 0 ? -1 : 1)) == -1)
		s[i++] = '-';
	i += ft_init_hex(s + i);
	res = f;
	while ((int)res != sign)
	{
		if ((sign == 1 ? (res > 1) : (res < -1)))
			res = f / ft_power(2, ++x);
		else
			res = f / ft_power(2, --x);
	}
	i += ft_ftohex2(s + i, res * sign);
	if ((s[i++] = 'p') && x > 0)
		s[i++] = '+';
	return (s = ft_strfjoin(s, ft_itoa(x), 1, 1));
}
