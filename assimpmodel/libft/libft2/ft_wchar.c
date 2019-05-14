/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/01 12:10:45 by edelangh          #+#    #+#             */
/*   Updated: 2015/01/08 10:49:36 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		wchar_to_string(unsigned char **s, wchar_t c)
{
	if (c < (1 << 7))
		*(*s)++ = (unsigned char)(c);
	else if (c < (1 << 11))
	{
		*(*s)++ = (unsigned char)((c >> 6) | 0xC0);
		*(*s)++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (c < (1 << 16))
	{
		*(*s)++ = (unsigned char)(((c >> 12)) | 0xE0);
		*(*s)++ = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		*(*s)++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (c < (1 << 21))
	{
		*(*s)++ = (unsigned char)(((c >> 18)) | 0xF0);
		*(*s)++ = (unsigned char)(((c >> 12) & 0x3F) | 0x80);
		*(*s)++ = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		*(*s)++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	else
		return (-1);
	return (0);
}

char	*cast_to_wc(va_list ap)
{
	unsigned char	wchar[5];
	unsigned char	*b;
	char			*str;
	wchar_t			c;

	b = wchar;
	c = va_arg(ap, wchar_t);
	wchar_to_string(&b, c);
	*b = '\0';
	str = ft_strdup((const char*)wchar);
	return (str);
}

char	*cast_to_ws(wchar_t *s)
{
	unsigned char	wchar[1024];
	unsigned char	*b;
	char			*str;
	wchar_t			c;
	int				i;

	b = wchar;
	if ((i = -1) && !s)
		return (NULL);
	while (s[++i])
	{
		c = s[i];
		if (wchar_to_string(&b, c) == -1)
			return ((char*)1);
	}
	*b = '\0';
	str = (char*)wchar;
	return (str);
}
