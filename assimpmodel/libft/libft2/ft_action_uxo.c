/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_uxo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 15:45:33 by edelangh          #+#    #+#             */
/*   Updated: 2015/01/23 11:40:34 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_action_ux(char *f, int lenud, va_list ap)
{
	t_printf		info;
	int				len;
	unsigned int	nbr;
	char			*tmp;

	info.type = 'X';
	init_info(&info, f, lenud, ap);
	if ((nbr = ft_get_value_ou(ap, &info)) == 2)
	{
		nbr = va_arg(ap, unsigned int);
		info.value = ft_zutoa((size_t)nbr);
	}
	tmp = info.value;
	info.value = ft_convert_base(info.value, "0123456789", "0123456789ABCDEF");
	free(tmp);
	len = ft_strlen(info.value);
	info.add = '\0';
	ft_print_d(info, len, nbr, (info.mark && nbr ? "0X" : ""));
	free(info.value);
	return (len);
}

int		ft_action_x(char *f, int lenud, va_list ap)
{
	t_printf		info;
	int				len;
	unsigned int	nbr;
	char			*tmp;

	info.type = 'x';
	init_info(&info, f, lenud, ap);
	if ((nbr = ft_get_value_ou(ap, &info)) == 2)
	{
		nbr = va_arg(ap, unsigned int);
		info.value = ft_zutoa((size_t)nbr);
	}
	tmp = info.value;
	info.value = ft_convert_base(info.value, "0123456789", "0123456789abcdef");
	free(tmp);
	len = ft_strlen(info.value);
	info.add = '\0';
	ft_print_d(info, len, nbr, (info.mark && nbr ? "0x" : ""));
	free(info.value);
	return (len);
}

int		ft_action_uo(char *f, int lenud, va_list ap)
{
	t_printf	info;
	int			len;
	size_t		nbr;
	char		*tmp;

	info.type = 'O';
	init_info(&info, f, lenud, ap);
	nbr = va_arg(ap, size_t);
	info.value = ft_zutoa(nbr);
	tmp = info.value;
	info.value = ft_convert_base(info.value, "0123456789", "01234567");
	free(tmp);
	len = ft_strlen(info.value);
	info.add = '\0';
	if (info.mark && nbr && info.preci)
		info.preci -= 1;
	else if (info.mark && !nbr && info.preci == 0)
		info.preci = 1;
	ft_print_d(info, len, nbr, (info.mark && nbr ? "0" : ""));
	free(info.value);
	return (len);
}

int		ft_action_o(char *f, int lenud, va_list ap)
{
	t_printf		info;
	int				len;
	unsigned int	nbr;
	char			*tmp;

	info.type = 'o';
	init_info(&info, f, lenud, ap);
	if ((nbr = ft_get_value_ou(ap, &info)) == 2)
	{
		nbr = va_arg(ap, unsigned int);
		info.value = ft_zutoa(nbr);
	}
	tmp = info.value;
	info.value = ft_convert_base(tmp, "0123456789", "01234567");
	free(tmp);
	len = ft_strlen(info.value);
	info.add = '\0';
	if (info.mark && nbr && info.preci)
		info.preci -= 1;
	else if (info.mark && !nbr && info.preci == 0)
		info.preci = 1;
	ft_print_d(info, len, nbr, (info.mark && nbr ? "0" : ""));
	free(info.value);
	return (len);
}

int		ft_action_u(char *f, int lenud, va_list ap, char type)
{
	t_printf		info;
	int				len;
	unsigned int	nbr;

	info.type = type;
	init_info(&info, f, lenud, ap);
	if ((nbr = ft_get_value_ou(ap, &info)) == 2)
	{
		nbr = va_arg(ap, unsigned int);
		info.value = ft_zutoa((size_t)nbr);
	}
	len = ft_strlen(info.value);
	if (type == 'u')
		info.add = '\0';
	ft_print_d(info, len, nbr != 0,
							(info.spad = ft_strjoinnchar(NULL, 1, info.add)));
	free(info.value);
	free(info.spad);
	return (len);
}
