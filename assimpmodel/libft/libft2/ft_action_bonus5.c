/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_bonus5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 19:22:30 by edelangh          #+#    #+#             */
/*   Updated: 2015/01/08 10:46:27 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	ft_get_read(t_printf *info, va_list ap)
{
	long double res;

	if (info->ul)
		res = va_arg(ap, long double);
	else if (info->l)
		res = (long double)va_arg(ap, double);
	else
		res = (long double)(float)va_arg(ap, double);
	return (res);
}

int			ft_action_e(char *f, int lenud, va_list ap)
{
	t_printf		info;
	int				len;
	long double		nbr;
	char			*x;

	info.type = 'e';
	init_info(&info, f, lenud, ap);
	nbr = (long double)va_arg(ap, double);
	x = ft_get_expo(&nbr);
	info.value = ft_ftoa(nbr);
	info.value = ft_fpreci(info.value, (info.is_preci ? info.preci : 6));
	info.value = ft_strfjoin(info.value, (x[0] == '-' ? "e" : "e+"), 1, 0);
	info.value = ft_strfjoin(info.value, x, 1, 1);
	len = ft_strlen(info.value);
	info.is_preci = 0;
	ft_print_d(info, len, nbr != 0, ft_strjoinnchar(NULL, 1, info.add));
	return (len);
}

int			ft_action_ue(char *f, int lenud, va_list ap)
{
	t_printf		info;
	int				len;
	long double		nbr;
	char			*x;

	info.type = 'E';
	init_info(&info, f, lenud, ap);
	nbr = (long double)va_arg(ap, double);
	x = ft_get_expo(&nbr);
	info.value = ft_ftoa(nbr);
	info.value = ft_fpreci(info.value, (info.is_preci ? info.preci : 6));
	info.value = ft_strfjoin(info.value, (x[0] == '-' ? "e" : "e+"), 1, 0);
	info.value = ft_strfjoin(info.value, x, 1, 1);
	ft_upper_case(info.value);
	len = ft_strlen(info.value);
	info.is_preci = 0;
	ft_print_d(info, len, nbr != 0, ft_strjoinnchar(NULL, 1, info.add));
	return (len);
}

int			ft_action_n(char *f, int lenud, va_list ap)
{
	t_printf	info;
	void		*nbr;

	info.type = 'n';
	init_info(&info, f, lenud, ap);
	nbr = va_arg(ap, void*);
	if (info.l == 2)
		*((long long*)nbr) = *(long long*)ft_static(0, 1);
	else if (info.l == 1)
		*((long*)nbr) = *(long*)ft_static(0, 1);
	else if (info.h == 2)
		*((signed char*)nbr) = *(signed char*)ft_static(0, 1);
	else if (info.h == 1)
		*((short*)nbr) = *(short*)ft_static(0, 1);
	else if (info.j == 1)
		*((intmax_t*)nbr) = *(intmax_t*)ft_static(0, 1);
	else if (info.z == 1)
		*((size_t*)nbr) = *(size_t*)ft_static(0, 1);
	else
		*((int*)nbr) = *(int*)ft_static(0, 1);
	return (0);
}
