/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 16:02:50 by edelangh          #+#    #+#             */
/*   Updated: 2015/03/04 14:34:54 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <termios.h>
#include <unistd.h>

void	ft_switch_icanon(void)
{
	struct termios	tattr;

	tcgetattr(0, &tattr);
	tattr.c_lflag ^= ECHO;
	tattr.c_lflag ^= ICANON;
	tattr.c_cc[VMIN] = 1;
	tattr.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &tattr);
}
