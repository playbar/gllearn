/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_untill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 19:28:22 by edelangh          #+#    #+#             */
/*   Updated: 2015/01/08 10:52:29 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_len_untill(const char *str, char c)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != c && str[len] != '\0')
		++len;
	return (len);
}
