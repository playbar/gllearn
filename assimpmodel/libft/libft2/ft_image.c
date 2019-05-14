/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 15:12:23 by edelangh          #+#    #+#             */
/*   Updated: 2016/03/25 11:36:18 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void	ft_fill_img(t_img *i, unsigned int color)
{
	int		x;
	int		y;

	x = -1;
	while (++x < i->width)
	{
		y = -1;
		while (++y < i->height)
		{
			i->udata[y * i->sl_div + x * i->bpp_div] = color;
		}
	}
}

t_uint	ft_get_pixel_from_image(t_img *i, int x, int y)
{
	unsigned int color;

	if (!i)
		return (0);
	if (x > i->width || x < 0 || y < 0 || y > i->height)
		return (0);
	color = i->udata[y * i->sl_div + x * i->bpp_div];
	return (color);
}

void	ft_pixel_put_to_image(t_img *i, int x, int y, unsigned int color)
{
	if (!i)
		return ;
	if (x >= i->width || x < 0 || y < 0 || y >= i->height)
		return ;
	i->udata[y * i->sl_div + x * i->bpp_div] = color;
}

t_img	*ft_load_img(void *mlx, char *src)
{
	t_img	*i;

	if (!src || !(i = (t_img*)ft_malloc(sizeof(t_img))))
		return (NULL);
	if (!(i->img = mlx_xpm_file_to_image(mlx, src, &(i->width), &(i->height))))
		return (NULL);
	i->data = mlx_get_data_addr(i->img, &(i->bpp),
								&(i->sizeline), &(i->endian));
	i->sl_div = i->sizeline / 4;
	i->bpp_div = i->bpp / 8 / 4;
	i->udata = (unsigned int*)i->data;
	return (i);
}

t_img	*ft_new_img(void *mlx, int width, int height)
{
	t_img	*i;

	if (!(i = (t_img*)ft_malloc(sizeof(t_img))))
		return (NULL);
	i->width = width;
	i->height = height;
	i->img = mlx_new_image(mlx, width, height);
	i->data = mlx_get_data_addr(i->img, &(i->bpp),
								&(i->sizeline), &(i->endian));
	i->sl_div = i->sizeline / 4;
	i->bpp_div = i->bpp / 8 / 4;
	i->udata = (unsigned int*)i->data;
	return (i);
}
