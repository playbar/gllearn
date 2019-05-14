/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_bonus3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 17:36:07 by edelangh          #+#    #+#             */
/*   Updated: 2015/01/08 11:03:01 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_f_preci(t_printf *info, long double nbr)
{
	int		len;
	char	*tmp;
	int		i;
	char	*tmp2;

	len = ft_strlen(info->value);
	if (info->is_preci)
	{
		tmp = ft_strchr(info->value, (info->type == 'a' ? 'p' : 'P'));
		i = (info->value[0] == '-' ? 5 : 4);
		if (len - ft_strlen(tmp) - i < (size_t)info->preci)
		{
			if (nbr == 0)
				info->value = ft_strinsert(info->value, ".", 3);
			tmp2 = ft_strfjoinnchar(NULL, len - ft_strlen(tmp) - i
									- info->preci + (nbr == 0), '0');
			info->value = ft_strinsert(info->value, tmp2, len
										- ft_strlen(tmp) + (nbr == 0));
		}
		else
			ft_memmove(info->value + info->preci + i, tmp, ft_strlen(tmp) + 1);
	}
	return (ft_strlen(info->value));
}

int		ft_action_a(char *f, int lenud, va_list ap)
{
	t_printf		info;
	int				len;
	double			nbr;

	info.type = 'a';
	init_info(&info, f, lenud, ap);
	nbr = va_arg(ap, double);
	info.value = ft_ftohex(nbr);
	len = ft_strlen(info.value);
	len = ft_f_preci(&info, nbr);
	ft_print_d(info, len, 1, "");
	return (len);
}

int		ft_action_ua(char *f, int lenud, va_list ap)
{
	t_printf		info;
	int				len;
	double			nbr;

	info.type = 'A';
	init_info(&info, f, lenud, ap);
	nbr = va_arg(ap, double);
	info.value = ft_upper_case(ft_ftohex(nbr));
	len = ft_strlen(info.value);
	len = ft_f_preci(&info, nbr);
	ft_print_d(info, len, 1, "");
	return (len);
}

int		ft_action_uf(char *f, int lenud, va_list ap)
{
	t_printf		info;
	int				len;
	double			nbr;

	info.type = 'F';
	init_info(&info, f, lenud, ap);
	nbr = va_arg(ap, double);
	info.value = ft_upper_case(ft_ftoa(nbr));
	info.value = ft_fpreci(info.value, info.preci);
	len = ft_strlen(info.value);
	info.is_preci = 0;
	ft_print_d(info, len, nbr != 0, ft_strjoinnchar(NULL, 1, info.add));
	return (len);
}
