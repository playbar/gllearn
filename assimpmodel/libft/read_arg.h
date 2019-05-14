/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arg.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 14:34:04 by edelangh          #+#    #+#             */
/*   Updated: 2015/05/13 16:04:25 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_ARG_H
# define READ_ARG_H

# include "libft.h"
# include "ft_printf.h"

/*
** if (!(arg = read_arg(ac, av, "o+", "%s : Error option %c\n"))
** 	exit(1);
*/

typedef struct	s_read_arg
{
	int			i;
	int			j;
	int			k;
	char		*posi;
	char		*on_error;
	char		*args;
}				t_read_arg;

void			skip_arg(int *ac, char ***av, char *posi);
char			*read_arg(int ac, char **av, char *posi, char *on_error);
char			*read_arg_move_av(int ac, char **av, char *posi, char *error);

#endif
