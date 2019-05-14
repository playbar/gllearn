/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 11:52:04 by edelangh          #+#    #+#             */
/*   Updated: 2015/01/08 10:47:42 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		init_info5(t_printf *info, int i, char *f)
{
	int j;

	j = i;
	if (f[i] == '\'' && (info->tild = 1))
		(void)1;
	else if (f[i] == 'z' && (info->z = 1))
		(void)1;
	else if (f[i] == '?' && (info->intero = 1))
		(void)1;
	return (i - j);
}

int		init_info4(t_printf *info, int i, char *f)
{
	int	j;

	if (f[(j = i)] == '#')
		info->mark = 1;
	else if (ft_isdigit(f[i]) && ((info->lpad = ft_atoi_printf(f + i)) || 1))
		while (ft_isdigit(f[i + 1]))
			++i;
	else if (f[i] == '.' && (info->is_preci = 1))
	{
		if (info->pad == '0' && !ft_strchr("sScC%", info->type))
			info->pad = ' ';
		info->preci = ft_atoi_printf(f + i + 1);
		while (ft_isdigit(f[i + 1]))
			++i;
	}
	else if (f[i] == 'l' && (info->l = 1))
	{
		if (f[i + 1] == 'l' && (info->l = 2))
			++i;
	}
	else if (f[i] == 'j' && (info->j = 1))
		(void)1;
	else
		return (init_info5(info, i, f));
	return (i - j);
}

int		init_info3(t_printf *info, int i, char *f, va_list ap)
{
	int	j;
	int	tmp;

	if (f[(j = i)] == '.' && f[i + 1] == '*')
	{
		if (++i && (tmp = va_arg(ap, int)) >= 0)
		{
			info->is_preci = 1;
			info->preci = tmp;
		}
	}
	else if (f[i] == '*' && (info->lpad = va_arg(ap, int)) < 0)
	{
		info->lpad = -info->lpad;
		if ((info->pad = ' '))
			info->rpad = 1;
	}
	else if (f[i] == 'h' && (info->h = 1))
	{
		if (f[i + 1] == 'h' && (info->h = 2))
			++i;
	}
	else
		i += init_info4(info, i, f);
	return (i - j);
}

int		init_info2(t_printf *info, int len, char *f, va_list ap)
{
	int i;

	i = 0;
	while (++i < len)
	{
		if (f[i] == '0')
		{
			if (!info->rpad && (!info->is_preci
						|| ft_strchr("sScC%", info->type)))
				info->pad = '0';
		}
		else if (f[i] == ' ' && info->add != '+')
			info->add = ' ';
		else if (f[i] == '+')
			info->add = '+';
		else if (f[i] == '-' && (info->rpad = 1))
			info->pad = ' ';
		else if (ft_select_f(info, &i, f))
			(void)1;
		else if (f[i] == 'L')
			info->ul = 1;
		else
			i += init_info3(info, i, f, ap);
	}
	return (i);
}

int		init_info(t_printf *info, char *f, int len, va_list ap)
{
	int		i;
	char	save;

	save = info->type;
	ft_bzero(info, sizeof(t_printf));
	info->pad = ' ';
	info->type = save;
	i = init_info2(info, len, f, ap);
	return (i + 1);
}
