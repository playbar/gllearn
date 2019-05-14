/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_bonus6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 15:40:23 by edelangh          #+#    #+#             */
/*   Updated: 2016/10/18 17:15:17 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

char	*ft_makecolor(char **str)
{
	*str = ft_strdup(*str);
	*str = ft_strfreplace(*str, "{red}", C_RED);
	*str = ft_strfreplace(*str, "{green}", C_GREEN);
	*str = ft_strfreplace(*str, "{blue}", C_BLUE);
	*str = ft_strfreplace(*str, "{magenta}", C_MAGENTA);
	*str = ft_strfreplace(*str, "{yellow}", C_YELLOW);
	*str = ft_strfreplace(*str, "{pink}", C_PINK);
	*str = ft_strfreplace(*str, "{cyan}", C_CYAN);
	*str = ft_strfreplace(*str, "{white}", C_WHITE);
	*str = ft_strfreplace(*str, "{gray}", C_GRAY);
	*str = ft_strfreplace(*str, "{blink}", C_BLINK);
	*str = ft_strfreplace(*str, "{eoc}", C_EOC);
	return (*str);
}

char	*ft_tild(t_printf *info, int *lenght)
{
	int		len;
	char	*space;

	space = localeconv()->decimal_point;
	len = ft_strlen(info->value) - ft_len_untill(info->value, '.');
	if (info->tild && ft_strchr("fF", info->type) && info->type)
		while (len > 3)
		{
			if (len + ft_len_untill(info->value, '.') != ft_strlen(info->value))
				info->value = ft_strinsert(info->value,
					space, len + ft_len_untill(info->value, '.'));
			len -= 3;
			(*lenght) += 1;
		}
	len = ft_len_untill(info->value, '.');
	if (info->tild && ft_strchr("duifF", info->type) && info->type)
		while (len > 3)
		{
			info->value = ft_strinsert(info->value, space, len - 3);
			len -= 3;
			(*lenght) += 1;
		}
	if (info->intero && ++(*lenght))
		info->value = ft_strjoinnchar(info->value, -1, info->type);
	return (info->value);
}
