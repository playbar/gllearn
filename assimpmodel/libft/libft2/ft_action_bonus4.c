/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_bonus4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 09:46:06 by edelangh          #+#    #+#             */
/*   Updated: 2015/01/08 10:46:22 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_expo(long double *a)
{
	long double	f;
	long double	x;
	int			sign;
	char		*s;

	x = 0;
	f = *a;
	if ((sign = (f < 0 ? -1 : 1)) == -1)
		(void)1;
	*a = f;
	while ((int)*a < -9 || (int)*a > 9 || ((int)*a == 0 && *a))
	{
		if ((sign == 1 ? (*a > 1) : (*a < -1)))
			*a = f / ft_power(10, ++x);
		else
			*a = f / ft_power(10, --x);
	}
	s = ft_itoa(x);
	if (((x >= 0 && x <= 9) || (x <= -1 && x >= -9) ? 1 : 0) && s[0] == '-')
		s = ft_strinsert(s, "0", 1);
	else if (((x >= 0 && x <= 9) || (x <= -1 && x >= -9) ? 1 : 0))
		s = ft_strjoinnchar(s, 1, '0');
	return (s);
}

int		ft_cut_nbr(char *s, int preci)
{
	int	i;
	int	count;
	int	is;

	ft_funtill(s);
	is = 0;
	count = 0;
	i = -1;
	if (!s)
		return (0);
	while (s[++i])
	{
		if (s[i] == '.')
			is = 1;
		if (s[i] >= '0' && s[i] <= '9')
			++count;
		if (is && count > preci)
			s[i] = '\0';
	}
	ft_funtill(s);
	return (i);
}

int		ft_cnbr(char *s)
{
	int	i;
	int	count;

	count = 0;
	i = -1;
	if (!s)
		return (0);
	while (s[++i])
		if (s[i] >= '0' && s[i] <= '9')
			++count;
	return (count);
}

int		ft_action_g(char *f, int lenud, va_list ap)
{
	t_printf		i;
	int				len;
	long double		nbr;
	char			*x;

	x = NULL;
	i.type = 'e';
	init_info(&i, f, lenud, ap);
	nbr = (long double)va_arg(ap, double);
	i.value = ft_ftoa(nbr);
	ft_cut_nbr(i.value, (i.is_preci ? i.preci : 6));
	if ((i.is_preci && !i.preci ? ft_cnbr(i.value) > 1 : 0)
			|| ft_cnbr(i.value) > (i.is_preci && i.preci ? i.preci : 6)
			|| (nbr >= -1e-5 && nbr <= 1e-5 && nbr))
	{
		x = ft_get_expo(&nbr);
		i.value = ft_ftoa(nbr);
		ft_cut_nbr(i.value, (i.is_preci ? i.preci : 6));
		i.value = ft_strfjoin(i.value, (x[0] == '-' ? "e" : "e+"), 1, 0);
		i.value = ft_strfjoin(i.value, x, 1, 1);
	}
	len = ft_strlen(i.value);
	ft_bzero(&(i.preci), sizeof(int) * 2);
	ft_print_d(i, len, nbr != 0, ft_strjoinnchar(NULL, 1, i.add));
	return (len);
}

int		ft_action_ug(char *f, int lenud, va_list ap)
{
	t_printf		i;
	int				len;
	long double		nbr;
	char			*x;

	x = NULL;
	i.type = 'e';
	init_info(&i, f, lenud, ap);
	nbr = (long double)va_arg(ap, double);
	i.value = ft_ftoa(nbr);
	ft_cut_nbr(i.value, (i.is_preci ? i.preci : 6));
	if ((i.is_preci && !i.preci ? ft_cnbr(i.value) > 1 : 0)
			|| ft_cnbr(i.value) > (i.is_preci && i.preci ? i.preci : 6)
			|| (nbr >= -1e-5 && nbr <= 1e-5 && nbr))
	{
		x = ft_get_expo(&nbr);
		i.value = ft_ftoa(nbr);
		ft_cut_nbr(i.value, (i.is_preci ? i.preci : 6));
		i.value = ft_strfjoin(i.value, (x[0] == '-' ? "e" : "e+"), 1, 0);
		i.value = ft_strfjoin(i.value, x, 1, 1);
	}
	len = ft_strlen(ft_upper_case(i.value));
	ft_bzero(&(i.preci), sizeof(int) * 2);
	ft_print_d(i, len, nbr != 0, ft_strjoinnchar(NULL, 1, i.add));
	return (len);
}
