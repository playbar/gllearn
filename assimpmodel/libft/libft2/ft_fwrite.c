/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwrite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 19:24:10 by edelangh          #+#    #+#             */
/*   Updated: 2015/02/05 16:33:37 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_static(void *val, int type)
{
	static int	fd;
	static int	len;
	static void	*tp;
	static void	*out;

	if (type == 0 || type == 3 || type == 4 || type == 8)
		len = 0;
	if (type == 0 && (tp = (void*)1))
		fd = *((int*)val);
	else if (type == 1)
		return (&len);
	else if (type == 2 && ((len += *((int*)val)) || 1))
		return (&fd);
	else if ((type == 3 || type == 4 || type == 8) && (tp = *(void**)&type))
		out = val;
	else if (type == 5)
		return (out);
	else if (type == 6)
		return ((len += *(int*)val) ? val : val);
	else if (type == 7)
		return (&len);
	return (&tp);
}

int		ft_strwrite(char *s, int len, int tp)
{
	int		i;
	int		*ptr;
	char	*str;
	int		j;

	j = 0;
	str = ft_static(0, 5);
	ptr = ft_static(0, 1);
	i = -1;
	if (tp == 3)
		str += *ptr;
	else if (tp == 8)
	{
		str = ft_strfjoinnchar(ft_strdup(*(char**)str), -(len + 1), '@');
		j = ft_strlen(str) - (1 + len);
	}
	*ptr += len;
	while (++i < len)
		str[i + j] = s[i];
	str[i + j] = '\0';
	if (tp == 8)
		*(char**)ft_static(0, 5) = str;
	return (0);
}

int		ft_print_s(t_printf *info, int len)
{
	if (info->rpad)
	{
		ft_fwrite(info->value, len);
		while (info->lpad-- - len > 0)
			ft_fwrite(&(info->pad), 1);
	}
	else
	{
		while (info->lpad-- - len > 0)
			ft_fwrite(&(info->pad), 1);
		ft_fwrite(info->value, len);
	}
	return (0);
}

int		ft_fwrite(char *s, int len)
{
	int	tp;

	tp = *((int*)ft_static(0, -1));
	if (tp == 1)
		write(*((int*)ft_static(&len, 2)), s, len);
	else if (tp == 3 || tp == 8)
		ft_strwrite(s, len, tp);
	else if (tp == 4)
		fwrite(s, sizeof(char), *(int*)ft_static(&len, 6),
				(FILE*)ft_static(0, 5));
	return (0);
}
