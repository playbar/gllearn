/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/01 12:41:21 by edelangh          #+#    #+#             */
/*   Updated: 2015/01/23 13:34:42 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <time.h>

char	*ft_itodate(char *i)
{
	char	*date;
	int		len;

	date = NULL;
	if ((len = ft_strlen(i)) % 2 == 1)
		i = ft_strfjoin("0", i, 0, 1);
	len = ft_strlen(i);
	if (len >= 2)
		date = ft_strsub(i, len - 2, 2);
	if (len >= 2 + 2)
	{
		date = ft_strfjoinnchar(date, -1, '/');
		date = ft_strfjoin(date, ft_strsub(i, len - 4, 2), 1, 1);
	}
	if (len >= 2 + 2 + 2)
	{
		date = ft_strfjoinnchar(date, -1, '/');
		if (len >= 4 + 2 + 2)
			date = ft_strfjoin(date, ft_strsub(i, 0, 4), 1, 1);
		else
			date = ft_strfjoin(date, ft_strsub(i, 0, 2), 1, 1);
	}
	free(i);
	return (date);
}

int		ft_action_t(char *f, int lenud, va_list ap)
{
	t_printf		info;
	int				len;
	time_t			nbr;

	info.type = 't';
	init_info(&info, f, lenud, ap);
	nbr = va_arg(ap, time_t);
	info.value = ctime(&nbr);
	len = ft_strlen(info.value);
	info.value[len - 1] = '\0';
	info.add = '\0';
	info.is_preci = 0;
	ft_print_d(info, len, nbr, "");
	free(info.value);
	return (len);
}

int		ft_action_k(char *f, int lenud, va_list ap)
{
	t_printf		info;
	int				len;
	unsigned int	nbr;

	info.type = 'k';
	init_info(&info, f, lenud, ap);
	nbr = va_arg(ap, unsigned int);
	info.value = ft_zutoa((size_t)nbr);
	info.value = ft_itodate(info.value);
	len = ft_strlen(info.value);
	info.add = '\0';
	info.preci = 0;
	ft_print_d(info, len, nbr, "");
	free(info.value);
	return (len);
}

int		ft_action_b(char *f, int lenud, va_list ap)
{
	t_printf		info;
	int				len;
	unsigned int	nbr;
	char			*tmp;

	info.type = 'b';
	init_info(&info, f, lenud, ap);
	if ((nbr = ft_get_value_ou(ap, &info)) == 2)
	{
		nbr = va_arg(ap, unsigned int);
		info.value = ft_zutoa((size_t)nbr);
	}
	tmp = info.value;
	info.value = ft_convert_base(info.value, "0123456789", "01");
	free(tmp);
	len = ft_strlen(info.value);
	info.add = '\0';
	ft_print_d(info, len, nbr, (info.mark && nbr ? "b" : ""));
	free(info.value);
	return (len);
}

int		ft_action_f(char *f, int lenud, va_list ap)
{
	t_printf		info;
	int				len;
	long double		nbr;
	char			*tmp;

	info.type = 'f';
	init_info(&info, f, lenud, ap);
	nbr = ft_get_read(&info, ap);
	info.value = ft_ftoa(nbr);
	if (info.is_preci)
		info.value = ft_fpreci(info.value, info.preci);
	len = ft_strlen(info.value);
	info.is_preci = 0;
	ft_print_d(info, len, nbr != 0, (tmp = ft_strjoinnchar(NULL, 1, info.add)));
	free(info.value);
	free(tmp);
	return (len);
}
