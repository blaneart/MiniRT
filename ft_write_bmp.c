/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_bmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 16:44:37 by ablanar           #+#    #+#             */
/*   Updated: 2020/01/02 15:22:23 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray.h"

void	ft_fill_bmp(t_bmp *bmp, unsigned wi, unsigned int he, int fd)
{
	static unsigned char header[54] = {66, 77, 0, 0, 0, 0, 0, 0, 0, 0, 54, 0,
			0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24};

	bmp->pixbyrow = wi * sizeof(t_pixel);
	bmp->padding = (4 - (bmp->pixbyrow % 4)) % 4;
	bmp->sizeoffile = (unsigned int	*)&header[2];
	bmp->hentry = (unsigned int	*)&header[22];
	bmp->wentry = (unsigned int	*)&header[18];
	*(bmp->sizeoffile) = 54 + (bmp->pixbyrow + bmp->padding) * he;
	bmp->wentry = (unsigned int *)&header[18];
	*(bmp->wentry) = wi;
	*(bmp->hentry) = he;
	write(fd, header, 54);
}

int		ft_bmp(char *fn, unsigned int wi, unsigned int he, t_pixel **pixels)
{
	int						fd;
	unsigned int			row;
	t_bmp					bmp;
	static unsigned char	zeroes[3] = {0, 0, 0};

	fd = open(fn, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP |
		S_IWGRP | S_IROTH | S_IWOTH);
	ft_fill_bmp(&bmp, wi, he, fd);
	row = 0;
	while (row < he)
	{
		write(fd, pixels[he - 1 - row], bmp.pixbyrow);
		write(fd, zeroes, bmp.padding);
		row++;
	}
	close(fd);
	return (0);
}

int		ft_clear_pix(t_pixel **pixels, int size, int max)
{
	int y;

	y = 0;
	while (y < size)
	{
		free(pixels[y]);
		y++;
	}
	free(pixels);
	if (size != max)
		return (-1);
	return (1);
}

void	ft_fill_p(t_pixel *p, unsigned char b, unsigned char g, unsigned char r)
{
	p->b = b;
	p->g = g;
	p->r = r;
}

int		ft_save(t_info info)
{
	int		x[2];
	int		color;
	t_pixel	**pixels;

	if (!(pixels = malloc(sizeof(t_pixel *) * info.res[1])))
		return (-1);
	x[1] = 0;
	ft_recalculate(&info.cam->norm, &g_up, &g_right);
	while (x[1] < info.res[1])
	{
		if (!(pixels[x[1]] = malloc(sizeof(t_pixel) * info.res[0])))
			return (ft_clear_pix(pixels, x[1], info.res[1]));
		x[0] = 0;
		while (x[0] < info.res[0])
		{
			color = ft_intersect(x[0], x[1], info);
			ft_fill_p(&pixels[x[1]][x[0]], ((color) & 0xFF),
			((color >> 8) & 0xFF), ((color >> 16) & 0xFF));
			x[0]++;
		}
		x[1]++;
	}
	ft_bmp("pic.bmp", info.res[0], info.res[1], pixels);
	return (ft_clear_pix(pixels, info.res[1], info.res[1]));
}
