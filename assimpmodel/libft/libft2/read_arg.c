/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 14:33:26 by edelangh          #+#    #+#             */
/*   Updated: 2016/03/25 11:41:29 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_arg.h"

static int		read_arg2(t_read_arg *a, char **av, char *posi, char *on_error)
{
	if (ft_strchr(posi, av[a->i][a->j]) && !ft_strchr("+", av[a->i][a->j]))
		a->args = ft_strfjoinnchar(a->args, -1, av[a->i][a->j]);
	else
	{
		if (on_error)
			ft_dprintf(2, on_error, av[0], av[a->i][a->j]);
		return (0);
	}
	if ((ft_strchr(posi, av[a->i][a->j])[a->k + 1] == '+'
				&& av[a->i + a->k + 1][0] != '-'))
	{
		while (ft_strchr(posi, av[a->i][a->j])[a->k + 1] == '+'
				&& av[a->i + a->k + 1][0] != '-')
		{
			++a->k;
			a->args = ft_strfjoinnchar(a->args, -1, ':');
			a->args = ft_strfjoin(a->args, av[a->i + a->k], 1, 0);
		}
		a->i += a->k;
		a->args = ft_strfjoinnchar(a->args, -1, ' ');
		return (1);
	}
	a->args = ft_strfjoinnchar(a->args, -1, ' ');
	return (2);
}

char			*read_arg(int ac, char **av, char *posi, char *on_error)
{
	t_read_arg	a;
	int			res;

	a.args = ft_memalloc(1);
	a.i = 0;
	while (++a.i < ac)
		if (av[a.i][0] == '-' && av[a.i][1] != '-'
				&& ft_atoi(av[a.i]) == 0)
		{
			a.j = 0;
			while (av[a.i][++a.j])
			{
				a.k = 0;
				if ((res = read_arg2(&a, av, posi, on_error)) == 0)
					return (NULL);
				else if (res == 1)
					break ;
			}
		}
		else
			break ;
	return (a.args);
}

void			skip_arg(int *ac, char ***av, char *posi)
{
	int		a;
	char	**b;
	char	*tmp;

	if (!ac || !av)
		return ;
	a = 0;
	b = *av;
	while (++a < *ac)
		if ((b[a][0] == '-' && b[a][1] != '-'
				&& ft_atoi(b[a]) == 0))
		{
			if ((tmp = ft_strchr(posi, b[a][1])))
				if (tmp[1] == '+')
					++a;
		}
		else if (!(b[a][0] == '-' && b[a][1] != '-'
				&& ft_atoi(b[a]) == 0))
		{
			if (b[a][1] == '-')
				++a;
			break ;
		}
	ft_memmove(&(b[1]), &(b[a]), sizeof(char*) * (*ac - a));
	*ac = *ac - a + 1;
}

char			*read_arg_move_av(int ac, char **av, char *posi, char *on_error)
{
	t_read_arg	a;
	int			res;

	a.args = ft_memalloc(1);
	a.i = 0;
	while (++a.i < ac)
		if (av[a.i][0] == '-' && av[a.i][1] != '-'
				&& ft_atoi(av[a.i]) == 0)
		{
			a.j = 0;
			while (av[a.i][++a.j])
			{
				a.k = 0;
				if ((res = read_arg2(&a, av, posi, on_error)) == 0)
					return (NULL);
				else if (res == 1)
					break ;
			}
		}
		else
			break ;
	if (a.i)
		ft_memmove(av, &(av[a.i - 1]), sizeof(char*) * (a.i - 1));
	return (a.args);
}
