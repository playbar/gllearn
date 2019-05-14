/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_sc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 15:45:23 by edelangh          #+#    #+#             */
/*   Updated: 2015/01/23 12:18:36 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_action_ud(char *f, int lenud, va_list ap, char type)
{
	t_printf		info;
	int				len;
	long long		nbr;

	info.type = type;
	init_info(&info, f, lenud, ap);
	nbr = (long long)va_arg(ap, long int);
	info.value = ft_lltoa(nbr);
	len = ft_strlen(info.value);
	ft_print_d(info, len, nbr != 0, ft_strjoinnchar(NULL, 1, info.add));
	free(info.value);
	return (len);
}

int		ft_action_s(char *f, int lenud, va_list ap, char type)
{
	t_printf	info;
	int			len;
	int			res;

	info.type = type;
	if (((res = init_info(&info, f, lenud, ap)) != -10) && info.l)
		return (ft_action_ls(f, lenud, ap, 'S'));
	info.value = ft_strdup(va_arg(ap, char*));
	if (!info.value)
		info.value = ft_strdup("(null)");
	if ((len = ft_strlen(info.value)) && info.is_preci && info.preci < len)
		len = info.preci;
	ft_print_s(&info, len);
	free(info.value);
	return (res);
}

int		ft_action_c(char *f, int lenud, va_list ap, char type)
{
	t_printf	info;
	int			len;

	info.type = 'c';
	init_info(&info, f, lenud, ap);
	info.type = type;
	if (info.l)
		return (ft_action_lc(f, lenud, ap, 'C'));
	if (type != 'c')
		info.value = ft_strjoinnchar(NULL, 1, type);
	else
		info.value = ft_strjoinnchar(NULL, 1, (char)va_arg(ap, int));
	if ((len = 1) && info.preci < len)
		info.preci = len;
	ft_print_s(&info, len);
	free(info.value);
	return (len);
}

int		ft_action_ls(char *f, int lenud, va_list ap, char type)
{
	t_printf	info;
	int			len;
	int			res;

	info.type = type;
	res = init_info(&info, f, lenud, ap);
	if ((info.value = cast_to_ws(va_arg(ap, wchar_t*))) == (char*)1)
		return (res);
	if (!info.value)
		info.value = ft_strdup("(null)");
	if ((len = ft_strlen(info.value)) && info.is_preci && info.preci < len)
		len = info.preci;
	ft_print_s(&info, len);
	free(info.value);
	return (res);
}

int		ft_action_lc(char *f, int lenud, va_list ap, char type)
{
	t_printf	info;
	int			len;
	int			c_len;

	info.type = type;
	init_info(&info, f, lenud, ap);
	info.value = cast_to_wc(ap);
	c_len = ft_strlen(info.value);
	if (info.preci < (len = 1))
		info.preci = len;
	if (info.rpad)
	{
		ft_fwrite(info.value, (c_len ? c_len : 1));
		while (info.lpad-- - len > 0)
			ft_fwrite(&(info.pad), 1);
	}
	else
	{
		while (info.lpad-- - len > 0)
			ft_fwrite(&(info.pad), 1);
		ft_fwrite(info.value, (c_len ? c_len : 1));
	}
	free(info.value);
	return (len);
}
