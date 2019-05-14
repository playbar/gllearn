/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 16:43:59 by edelangh          #+#    #+#             */
/*   Updated: 2016/10/24 13:45:38 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

char	*ft_strquote(char *cmd)
{
	size_t	i;
	char	quote;

	quote = 0;
	i = -1;
	while (cmd[++i])
	{
		if (cmd[i] == '\\'
			&& (cmd[i + 1] == '\"' || cmd[i + 1] == '\\' || cmd[i + 1] == '\''))
		{
			ft_memmove(cmd + i, cmd + i + 1, ft_strlen(cmd + i));
			cmd[i] = -cmd[i];
		}
		else if (((cmd[i] == '\"' || (cmd[i] == '\''))
					&& (!quote || quote == cmd[i])))
		{
			quote = (quote ? 0 : cmd[i]);
			ft_memmove(cmd + i, cmd + i + 1, ft_strlen(cmd + i));
			--i;
		}
		else if (quote)
			cmd[i] = -cmd[i];
	}
	return (cmd);
}

char	*ft_echap_cmd(char *cmd)
{
	char	*echap;
	size_t	len;

	echap = ft_strnew(ft_strlen(cmd));
	len = -1;
	while (cmd[++len])
	{
		if (cmd[len] == '\\' && cmd[len + 1])
		{
			echap[len] = 1;
			ft_memmove(cmd + len, cmd + len + 1, ft_strlen(cmd + len));
		}
		else
			echap[len] = -1;
	}
	echap[len] = '\0';
	return (echap);
}

char	*ft_build_cmd(char *cmd)
{
	int		i;
	char	*echap;

	cmd = ft_strquote(cmd);
	echap = ft_echap_cmd(cmd);
	i = -1;
	while (cmd[++i])
	{
		if (echap[i] == 1)
			cmd[i] = -cmd[i];
	}
	free(echap);
	return (cmd);
}

char	**ft_splitcmd(char *cmd)
{
	char	**splited;
	int		i;
	int		j;

	i = -1;
	cmd = ft_strdup(cmd);
	cmd = ft_strfreplace(cmd, " \"\"", " \177");
	cmd = ft_strfreplace(cmd, " \'\'", " \177");
	cmd = ft_build_cmd(cmd);
	splited = ft_strsplit(cmd, ' ');
	free(cmd);
	while (splited[++i])
	{
		j = -1;
		while (splited[i][++j])
		{
			if (!ft_strcmp(splited[i], "\177"))
				splited[i] = ft_strfreplace(splited[i], "\177", "");
			if (splited[i][j] < 0)
				splited[i][j] = -splited[i][j];
		}
	}
	return (splited);
}
