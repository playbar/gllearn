/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 11:00:36 by edelangh          #+#    #+#             */
/*   Updated: 2015/01/08 11:02:25 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ll_len(long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		++len;
		n *= -1;
	}
	while (n)
	{
		++len;
		n /= 10;
	}
	return (len);
}

char		*ft_lltoa(long long n)
{
	char	*s;
	int		len;

	len = ft_ll_len(n);
	s = ft_strnew(len);
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		n = -n;
		if (n < 0)
			return (ft_strdup("-9223372036854775808"));
		s[0] = '-';
	}
	while (n)
	{
		--len;
		s[len] = '0' + n % 10;
		n /= 10;
	}
	return (s);
}
