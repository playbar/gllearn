/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 15:45:45 by edelangh          #+#    #+#             */
/*   Updated: 2015/01/23 10:49:02 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_rd(t_printf info, int len, int nbr, char *add)
{
	int	i;

	if (info.value[0] == '-')
	{
		ft_memmove(info.value, info.value + 1, len--);
		add = "-";
	}
	if (!nbr && info.is_preci)
		len = 0;
	info.lpad -= ft_strlen(add);
	if (info.pad == '0')
	{
		info.preci += info.lpad;
		info.lpad = 0;
	}
	info.preci = (info.preci < len ? len : info.preci);
	ft_fwrite(add, ft_strlen(add));
	i = info.preci;
	while (info.preci-- - len > 0)
		ft_fwrite("0", 1);
	ft_fwrite(info.value, len);
	while (info.lpad-- - i > 0)
		ft_fwrite(&(info.pad), 1);
	return (0);
}

int		ft_print_d(t_printf info, int len, int nbr, char *add)
{
	info.value = ft_tild(&info, &len);
	if (info.rpad)
		return (ft_print_rd(info, len, nbr, add));
	if (info.value[0] == '-')
	{
		ft_memmove(info.value, info.value + 1, len);
		--len;
		add = "-";
	}
	if (!nbr && info.is_preci)
		len = 0;
	info.lpad -= ft_strlen(add);
	if (info.pad == '0')
	{
		info.preci += info.lpad;
		info.lpad = 0;
	}
	info.preci = (info.preci < len ? len : info.preci);
	while (info.lpad-- - info.preci > 0)
		ft_fwrite(&(info.pad), 1);
	ft_fwrite(add, ft_strlen(add));
	while (info.preci-- - len > 0)
		ft_fwrite("0", 1);
	ft_fwrite(info.value, len);
	return (0);
}
