/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 14:06:26 by edelangh          #+#    #+#             */
/*   Updated: 2016/03/25 14:52:16 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	va_list		ap;
	int			len;
	int			res;
	int			fd;
	char		*tmp;

	ft_static(&fd, (fd = 1) == 2);
	va_start(ap, format);
	ft_va_get(ap, 0);
	if (!format)
		return (-1);
	tmp = ft_makecolor(&format);
	while (*format)
	{
		len = ft_len_untill(format, '%');
		ft_fwrite(format, len);
		format += len;
		if (*format == '%' && (res = ft_action(format, ap)) == -1)
			return (*((int*)ft_static(0, 1)));
		else if (*format == '%')
			format += res;
	}
	va_end(ap);
	return (*((int*)ft_static(0, 1)) + ft_free(tmp));
}

int		ft_dprintf(int fd, char *format, ...)
{
	va_list		ap;
	int			len;
	int			res;
	char		*tmp;

	ft_static(&fd, 0);
	va_start(ap, format);
	ft_va_get(ap, 0);
	if (!format)
		return (-1);
	tmp = ft_makecolor(&format);
	while (*format)
	{
		len = ft_len_untill(format, '%');
		ft_fwrite(format, len);
		format += len;
		if (*format == '%' && (res = ft_action(format, ap)) == -1)
			return (*((int*)ft_static(0, 1)));
		else if (*format == '%')
			format += res;
	}
	va_end(ap);
	return (*((int*)ft_static(0, 1)) + ft_free(tmp));
}

int		ft_sprintf(char *str, char *format, ...)
{
	va_list		ap;
	int			len;
	int			res;
	char		*tmp;

	if (!format)
		return (-1);
	ft_static(str, 3);
	va_start(ap, format);
	ft_va_get(ap, 0);
	tmp = ft_makecolor(&format);
	while (*format)
	{
		len = ft_len_untill(format, '%');
		ft_fwrite(format, len);
		format += len;
		if (*format == '%')
		{
			if ((res = ft_action(format, ap)) == -1)
				return (*((int*)ft_static(0, 1)));
			format += res;
		}
	}
	va_end(ap);
	return (*((int*)ft_static(0, 1)) + ft_free(tmp));
}

int		ft_asprintf(char **ret, char *format, ...)
{
	va_list		ap;
	int			len;
	int			res;
	char		*tmp;

	if (!format || !ret)
		return (-1);
	*ret = NULL;
	ft_static(ret, 8);
	va_start(ap, format);
	ft_va_get(ap, 0);
	tmp = ft_makecolor(&format);
	while (*format)
	{
		len = ft_len_untill(format, '%');
		ft_fwrite(format, len);
		format += len;
		if (*format == '%' && (res = ft_action(format, ap)) == -1)
			return (*((int*)ft_static(0, 1)));
		else if (*format == '%')
			format += res;
	}
	va_end(ap);
	return (*((int*)ft_static(0, 1)) + ft_free(tmp));
}

int		ft_fprintf(FILE *file, char *format, ...)
{
	va_list		ap;
	int			len;
	int			res;
	char		*tmp;

	ft_static(file, 4);
	va_start(ap, format);
	ft_va_get(ap, 0);
	if (!format || !file)
		return (-1);
	tmp = ft_makecolor(&format);
	while (*format)
	{
		len = ft_len_untill(format, '%');
		ft_fwrite(format, len);
		format += len;
		if (*format == '%')
		{
			if ((res = ft_action(format, ap)) == -1)
				return (*((int*)ft_static(0, 1)));
			format += res;
		}
	}
	va_end(ap);
	return (*((int*)ft_static(0, 1)) + ft_free(tmp));
}
