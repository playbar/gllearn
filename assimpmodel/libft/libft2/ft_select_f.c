/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 14:34:43 by edelangh          #+#    #+#             */
/*   Updated: 2015/01/08 10:48:33 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_va_get(va_list new, int pos)
{
	static va_list	save;
	va_list			ap;
	int				res;

	if (new)
		va_copy(save, new);
	else
	{
		va_copy(ap, save);
		while (pos--)
			res = va_arg(ap, int);
		return (res);
	}
	return (0);
}

int		ft_is_select_f(char *f, int i)
{
	if (f[i] == '.')
		++i;
	if (f[i] == '*')
	{
		++i;
		if (f[i] >= '0' && f[i] <= '9')
		{
			while (f[i] >= '0' && f[i] <= '9')
				++i;
			return ((f[i] == '$' ? i : 0));
		}
	}
	return (0);
}

int		ft_select_f(t_printf *info, int *i, char *f)
{
	int	value;

	if (ft_is_select_f(f, *i))
	{
		value = ft_atoi_printf(f + *i + 1);
		if (f[*i] == '.' && (info->is_preci = 1))
			info->preci = ft_va_get(NULL, value);
		else
		{
			if ((info->lpad = ft_va_get(NULL, value)) < 0)
			{
				info->lpad = -info->lpad;
				info->rpad = ' ';
			}
		}
		*i += ft_len_untill(f + *i, '$');
		return (1);
	}
	return (0);
}
