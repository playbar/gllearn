/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 10:58:21 by edelangh          #+#    #+#             */
/*   Updated: 2015/05/07 18:08:43 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_action_narg(char *s, va_list ap)
{
	int	len;

	len = 1;
	while (ft_strchr("#.0lhjz+-L'$*? 123456789", s[len]) && s[len])
		++len;
	if (s[len])
		ft_action_c(s, len, ap, s[len]);
	else
		return (-2);
	return (len);
}

int		ft_is_arg(char c)
{
	if (ft_strchr("#.0lhjz+- 123456789*$'L?", c) && c)
		return (1);
	return (0);
}

int		ft_action3(char *f, va_list ap, int len)
{
	if (f[len] == 'a')
		ft_action_a(f, len, ap);
	else if (f[len] == 'A')
		ft_action_ua(f, len, ap);
	else if (f[len] == 'F')
		ft_action_uf(f, len, ap);
	else if (f[len] == 'e')
		ft_action_e(f, len, ap);
	else if (f[len] == 'E')
		ft_action_ue(f, len, ap);
	else if (f[len] == 'g')
		ft_action_g(f, len, ap);
	else if (f[len] == 'G')
		ft_action_ug(f, len, ap);
	else if (f[len] == 'n')
		ft_action_n(f, len, ap);
	else
		len = ft_action_narg(f, ap);
	return (len + 1);
}

int		ft_action2(char *f, va_list ap, int len)
{
	if (f[len] == 'p')
		ft_action_p(f, len, ap);
	else if (f[len] == 'S')
		ft_action_ls(f, len, ap, f[len]);
	else if (f[len] == 's')
		ft_action_s(f, len, ap, f[len]);
	else if (f[len] == 'C')
		ft_action_lc(f, len, ap, f[len]);
	else if (f[len] == 'c' || f[len] == '%')
		ft_action_c(f, len, ap, f[len]);
	else if (f[len] == 'b')
		ft_action_b(f, len, ap);
	else if (f[len] == 'k')
		ft_action_k(f, len, ap);
	else if (f[len] == 't')
		ft_action_t(f, len, ap);
	else if (f[len] == 'r')
		ft_action_r(f, len, ap, f[len]);
	else if (f[len] == 'H')
		ft_action_uh(f, len, ap, f[len]);
	else if (f[len] == 'f')
		ft_action_f(f, len, ap);
	else
		return (ft_action3(f, ap, len));
	return (len + 1);
}

int		ft_action(char *f, va_list ap)
{
	int		len;

	len = 1;
	while (ft_is_arg(f[len]))
		++len;
	if (f[len] == 'i' || f[len] == 'd')
		ft_action_d(f, len, ap, f[len]);
	else if (f[len] == 'D')
		ft_action_ud(f, len, ap, f[len]);
	else if (f[len] == 'U')
		ft_action_zu(f, len, ap, f[len]);
	else if (f[len] == 'u')
		ft_action_u(f, len, ap, f[len]);
	else if (f[len] == 'O')
		ft_action_uo(f, len, ap);
	else if (f[len] == 'o')
		ft_action_o(f, len, ap);
	else if (f[len] == 'X')
		ft_action_ux(f, len, ap);
	else if (f[len] == 'x')
		ft_action_x(f, len, ap);
	else
		return (ft_action2(f, ap, len));
	return (len + 1);
}
