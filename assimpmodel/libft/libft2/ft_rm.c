/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 17:15:33 by edelangh          #+#    #+#             */
/*   Updated: 2015/01/31 17:53:53 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

int		ft_rm(char *name)
{
	DIR				*directory;
	struct dirent	*entry;
	struct stat		file_stat;
	char			buffer[10024];

	if (stat(name, &file_stat) == -1)
		return (-1);
	if (S_ISREG(file_stat.st_mode))
		return (remove(name));
	ft_bzero(buffer, sizeof(buffer));
	if (!(directory = opendir(name)))
		return (-1);
	while ((entry = readdir(directory)) != NULL)
	{
		if (!ft_strcmp(entry->d_name, ".") || !ft_strcmp(entry->d_name, ".."))
			continue ;
		ft_sprintf(buffer, "%s/%s", name, entry->d_name);
		stat(buffer, &file_stat);
		if (S_ISREG(file_stat.st_mode))
			remove(buffer);
		else if (S_ISDIR(file_stat.st_mode))
			ft_rm(buffer);
	}
	closedir(directory);
	return (remove(name));
}
