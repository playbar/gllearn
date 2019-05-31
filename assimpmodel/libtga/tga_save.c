/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:34:39 by snicolet          #+#    #+#             */
/*   Updated: 2018/04/26 17:34:41 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
//#include "libft2.h"
#include "tga.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

/*
** export pixels to a tga filepath, if the file already exists it will be
** replaced
** returns:
** 0 = everything was ok, no error
** 1 = wrong header type or memdup failed
** 2 = failed to open destination file, check permissions
*/

void *memdup(const void *src, size_t n)
{
    void	*out;
    void	*dst;

    if ((out = malloc(n)) == NULL)
        return (NULL);
    dst = out;
    while (n--)
        *(unsigned char*)dst++ = *(unsigned char*)src++;
    return (out);
}

int	tga_save(const char *filepath, const t_tga *specs,
	const unsigned int *pixels)
{
	const size_t	size = specs->height * specs->width;
    FILE*			fd;
	unsigned int	*px;
	size_t			p;

	if ((specs->type != TGA_TYPE_TC_RAW) ||
			(!(px = memdup(pixels, size << 2))))
		return (1);
    fd = fopen(filepath, "wb");
    if( fd == NULL )
    {
        free(px);
        return 2;
    }

	p = size;
	while (p--)
		px[p] = TGA_S(px[p]);
	fwrite(specs, TGA_SIZE, 1, fd);
	fwrite(px, size << 2, 1, fd);
	fclose(fd);
	free(px);
	return (0);
}
