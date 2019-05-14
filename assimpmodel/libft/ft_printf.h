/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 14:10:25 by edelangh          #+#    #+#             */
/*   Updated: 2015/01/23 10:53:02 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include <stdio.h>
# include "libft.h"

typedef struct	s_printf
{
	char		type;
	char		*value;
	int			rpad;
	int			lpad;
	char		pad;
	char		*spad;
	char		add;
	int			mark;
	int			preci;
	int			is_preci;
	int			h;
	int			l;
	int			ul;
	int			j;
	int			z;
	int			tild;
	int			intero;
}				t_printf;

int				ft_printf(char *format, ...);
int				ft_dprintf(int fd, char *format, ...);
int				ft_sprintf(char *str, char *format, ...);
int				ft_fprintf(FILE *file, char *format, ...);
int				ft_asprintf(char **str, char *format, ...);

char			*cast_to_wc(va_list ap);
char			*cast_to_ws(wchar_t *s);
int				ft_atoi_printf(char *str);
int				init_info(t_printf *info, char *f, int len, va_list ap);
int				ft_print_d(t_printf info, int len, int nbr, char *add);
int				ft_get_value_ou(va_list ap, t_printf *info);
int				ft_action_ud(char *f, int lenud, va_list ap, char type);
int				ft_action_o(char *f, int lenud, va_list ap);
int				ft_action_uo(char *f, int lenud, va_list ap);
int				ft_action_x(char *f, int lenud, va_list ap);
int				ft_action_ux(char *f, int lenud, va_list ap);
int				ft_get_value_ou(va_list ap, t_printf *info);
int				ft_get_value_d(va_list ap, t_printf *info);
int				ft_action_p(char *f, int lenud, va_list ap);
int				ft_action_d(char *f, int lenud, va_list ap, char type);
int				ft_action_zu(char *f, int lenud, va_list ap, char type);
int				ft_action_c(char *f, int lenud, va_list ap, char type);
int				ft_action_s(char *f, int lenud, va_list ap, char type);
int				ft_action_lc(char *f, int lenud, va_list ap, char type);
int				ft_action_ls(char *f, int lenud, va_list ap, char type);
int				ft_print_rd(t_printf info, int len, int nbr, char *add);
int				ft_print_d(t_printf info, int len, int nbr, char *add);
int				ft_action_u(char *f, int lenud, va_list ap, char type);
int				ft_action_b(char *f, int lenud, va_list ap);
int				ft_action_t(char *f, int lenud, va_list ap);
int				ft_action_k(char *f, int lenud, va_list ap);
int				ft_action_r(char *f, int lenud, va_list ap, char type);
int				ft_action_uh(char *f, int lenud, va_list ap, char type);
int				ft_action_f(char *f, int lenud, va_list ap);
int				ft_action_uf(char *f, int lenud, va_list ap);
char			*ft_ftoa(long double c);
char			*ft_fpreci(char *hex, int preci);
char			*ft_ftohex(long double c);
int				ft_action_a(char *f, int lenud, va_list ap);
int				ft_action_ua(char *f, int lenud, va_list ap);
int				ft_action_e(char *f, int lenud, va_list ap);
int				ft_action_ue(char *f, int lenud, va_list ap);
int				ft_action_g(char *f, int lenud, va_list ap);
int				ft_action_ug(char *f, int lenud, va_list ap);
int				ft_action_n(char *f, int lenud, va_list ap);
char			*ft_upper_case(char *s);
long double		ft_power(long double base, long double ex);
int				ft_funtill(char *s);
char			*ft_strinsert(char *a, char *b, int pos);
char			*ft_get_expo(long double *a);
int				ft_fwrite(char *s, int len);
int				ft_print_s(t_printf *info, int len);
void			*ft_static(void *val, int type);
int				ft_select_f(t_printf *info, int *i, char *f);
int				ft_va_get(va_list new, int pos);
long double		ft_get_read(t_printf *info, va_list ap);
int				ft_action(char *f, va_list ap);
int				ft_is_arg(char c);
char			*ft_makecolor(char **str);
int				ft_is_arg(char c);
char			*ft_tild(t_printf *info, int *lenght);
#endif
