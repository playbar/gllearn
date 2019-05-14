/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 18:35:44 by edelangh          #+#    #+#             */
/*   Updated: 2015/02/01 12:43:46 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void	ft_resize_img(t_img *to, t_img *i, int *pos, int *size)
{
	double			x;
	double			y;
	unsigned int	clr;
	double			rx;
	double			ry;

	rx = size[0] / (double)size[2];
	ry = size[1] / (double)size[3];
	x = -1;
	while (++x < size[2])
	{
		y = -1;
		while (++y < size[3])
		{
			clr = ft_get_pixel_from_image(i, x * rx + pos[0], y * ry + pos[1]);
			if (clr != 0xFFFFFF)
				ft_pixel_put_to_image(to, pos[2] + x, pos[3] + y, clr);
		}
	}
}

int		ft_destroy_img(void *mlx, t_img *i)
{
	if (i)
	{
		mlx_destroy_image(mlx, i->img);
		free(i);
	}
	return (0);
}
