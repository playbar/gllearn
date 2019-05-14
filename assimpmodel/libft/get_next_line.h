/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 14:45:21 by edelangh          #+#    #+#             */
/*   Updated: 2014/11/28 16:10:45 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE 128

typedef struct			s_fd_list
{
	int					fd;
	char				*buffer;
	int					lline;
	struct s_fd_list	*next;
}						t_fd_list;

int						get_next_line(int const fd, char **line);
#endif
