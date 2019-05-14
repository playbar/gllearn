/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_bonus2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/01 17:08:05 by edelangh          #+#    #+#             */
/*   Updated: 2015/01/30 14:07:36 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strfhex(char *c)
{
	int		i;
	char	*s;
	char	*tmp;

	s = ft_strnew(0);
	i = -1;
	while (c[++i])
	{
		tmp = ft_strfjoin(ft_convert_base(ft_itoa((int)c[i]), "0123456789",
					"0123456789ABCDEF"), " ", 1, 0);
		if (ft_strlen(tmp) == 2)
			tmp = ft_strfjoinnchar(tmp, 1, '0');
		s = ft_strfjoin(s, tmp, 1, 1);
	}
	if (ft_strlen(s) > 1)
		s[ft_strlen(s) - 1] = '\0';
	return (s);
}

int		ft_action_uh(char *f, int lenud, va_list ap, char type)
{
	t_printf	info;
	int			len;
	int			res;

	info.type = type;
	res = init_info(&info, f, lenud, ap);
	info.value = ft_strdup(va_arg(ap, char*));
	info.value = ft_strfhex(info.value);
	if (!info.value)
		info.value = ft_strdup("(null)");
	if ((len = ft_strlen(info.value)) && info.is_preci && info.preci < len)
		len = info.preci;
	ft_print_s(&info, len);
	return (res);
}

char	*ft_strfall(char *c)
{
	char	*s;
	char	*tmp;
	int		i;

	i = -1;
	s = c;
	while ((tmp = ft_strchr(s, '\t')))
		s = ft_strfjoin(ft_strfjoin(ft_strsub(s, 0, tmp - s), "^I", 1, 0),
						tmp + 1, 1, 0);
	while ("\1\2\3\4\5\6\7\10\11\13\14\15\16\17"[++i])
		while ((tmp = ft_strchr(s, "\1\2\3\4\5\6\7\10\11\13\14\15\16\17"[i])))
			s = ft_strfjoin(ft_strfjoin(ft_strsub(s, 0, tmp - s), "^X", 1, 0),
							tmp + 1, 1, 0);
	while ((tmp = ft_strchr(s, '\177')))
		s = ft_strfjoin(ft_strfjoin(ft_strsub(s, 0, tmp - s), "^?", 1, 0),
						tmp + 1, 1, 0);
	while ((tmp = ft_strchr(s + i, '\n')))
		s = ft_strfjoin(ft_strfjoin(ft_strsub(s, 0, tmp - s), "\177", 1, 0),
						tmp + 1, 1, 0);
	while ((tmp = ft_strchr(s + i, '\177')))
		s = ft_strfjoin(ft_strfjoin(ft_strsub(s, 0, tmp - s), "$\n", 1, 0),
						tmp + 1, 1, 0);
	return (s);
}

int		ft_action_r(char *f, int lenud, va_list ap, char type)
{
	t_printf	info;
	int			len;
	int			res;

	info.type = type;
	res = init_info(&info, f, lenud, ap);
	info.value = ft_strdup(va_arg(ap, char*));
	info.value = ft_strfall(info.value);
	if (!info.value)
		info.value = ft_strdup("(null)");
	if ((len = ft_strlen(info.value)) && info.is_preci && info.preci < len)
		len = info.preci;
	ft_print_s(&info, len);
	return (res);
}
