/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_dp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 15:45:06 by edelangh          #+#    #+#             */
/*   Updated: 2015/01/23 11:00:50 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_value_ou(va_list ap, t_printf *info)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (info->l == 2 && ((i = va_arg(ap, unsigned long long)) || 1))
		info->value = ft_zutoa(i);
	else if (info->l == 1 && ((i = va_arg(ap, unsigned long int)) || 1))
		info->value = ft_zutoa(i);
	else if (info->h == 2 && ((i = (unsigned char)va_arg(ap, int)) || 1))
		info->value = ft_itoa(i);
	else if (info->h == 1 && ((i = (unsigned short)va_arg(ap, int)) || 1))
		info->value = ft_itoa(i);
	else if (info->j == 1 && ((i = va_arg(ap, uintmax_t)) || 1))
		info->value = ft_zutoa(i);
	else if (info->z == 1 && ((i = va_arg(ap, size_t)) || 1))
		info->value = ft_zutoa(i);
	else
		return (2);
	return ((i != 0 || j != 0 ? 1 : 0));
}

int		ft_get_value_d(va_list ap, t_printf *info)
{
	long long	i;
	size_t		j;

	j = 0;
	i = 0;
	if (info->l == 2 && ((i = va_arg(ap, long long int)) || 1))
		info->value = ft_lltoa(i);
	else if (info->l == 1 && ((i = va_arg(ap, long int)) || 1))
		info->value = ft_lltoa(i);
	else if (info->h == 2 && ((i = (signed char)va_arg(ap, int)) || 1))
		info->value = ft_itoa(i);
	else if (info->h == 1 && ((i = (short)va_arg(ap, int)) || 1))
		info->value = ft_itoa(i);
	else if (info->j == 1 && ((i = va_arg(ap, intmax_t)) || 1))
		info->value = ft_lltoa(i);
	else if (info->z == 1 && ((i = va_arg(ap, long long)) || 1))
		info->value = ft_lltoa(i);
	else if ((i = va_arg(ap, int)) || 1)
		info->value = ft_itoa(i);
	return ((i != 0 || j != 0 ? 1 : 0));
}

int		ft_action_p(char *f, int lenud, va_list ap)
{
	t_printf	info;
	int			len;
	size_t		nbr;
	char		*tmp;

	info.type = 'p';
	init_info(&info, f, lenud, ap);
	nbr = va_arg(ap, size_t);
	tmp = ft_zutoa(nbr);
	info.value = ft_convert_base(tmp, "0123456789", "0123456789abcdef");
	free(tmp);
	len = ft_strlen(info.value);
	info.add = '\0';
	ft_print_d(info, len, nbr, "0x");
	free(info.value);
	return (len);
}

int		ft_action_d(char *f, int lenud, va_list ap, char type)
{
	t_printf	info;
	int			len;
	int			nbr;

	info.type = type;
	init_info(&info, f, lenud, ap);
	nbr = ft_get_value_d(ap, &info);
	len = ft_strlen(info.value);
	ft_print_d(info, len, nbr != 0,
							(info.spad = ft_strjoinnchar(NULL, 1, info.add)));
	free(info.value);
	free(info.spad);
	return (len);
}

int		ft_action_zu(char *f, int lenud, va_list ap, char type)
{
	t_printf		info;
	int				len;
	size_t			nbr;

	info.type = type;
	init_info(&info, f, lenud, ap);
	nbr = va_arg(ap, size_t);
	info.value = ft_zutoa((size_t)nbr);
	len = ft_strlen(info.value);
	if (type == 'U')
		info.add = '\0';
	ft_print_d(info, len, nbr != 0,
							(info.spad = ft_strjoinnchar(NULL, 1, info.add)));
	free(info.value);
	free(info.spad);
	return (len);
}
