/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/01 18:49:04 by edelangh          #+#    #+#             */
/*   Updated: 2015/01/23 13:35:46 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_funtill(char *s)
{
	int	i;
	int	len;

	i = 0;
	if (!ft_strchr(s, '.'))
		return (0);
	len = ft_strlen(s) - 1;
	while (s[len - i] == '0')
	{
		s[len - i] = '\0';
		++i;
	}
	if (s[len - i] == '.')
		s[len - i] = '\0';
	return (0);
}

char	*ft_fpreci(char *s, int preci)
{
	char	*new;
	int		len;
	int		len_a;
	int		len_b;

	len = ft_strlen(s);
	len_a = ft_len_untill(s, '.');
	len_b = len - len_a - 1;
	new = ft_strdup(s);
	free(s);
	if (preci == 0)
		new[ft_len_untill(new, '.')] = '\0';
	else if (len_b > preci)
		new[preci + len_a + 1] = '\0';
	else
		new = ft_strfjoinnchar(new, -preci + len_b, '0');
	return (new);
}

char	*ft_ftoa(long double f)
{
	long long	a;
	long long	b;
	char		*s;
	char		*tmp;

	a = (long long)f;
	f = f - (long double)a;
	b = (int)(f * 1000000);
	if (b < 0)
		b = -b;
	s = ft_lltoa(a);
	s = ft_strfjoinnchar(s, -1, '.');
	tmp = ft_lltoa(b);
	if (6 - ft_strlen(tmp) > 0)
		tmp = ft_strfjoinnchar(tmp, 6 - ft_strlen(tmp), '0');
	s = ft_strfjoin(s, tmp, 1, 1);
	if (f < 0 && s[0] != '-')
		s = ft_strfjoinnchar(s, 1, '-');
	return (s);
}
