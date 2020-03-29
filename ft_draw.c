/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:46:40 by ablanar           #+#    #+#             */
/*   Updated: 2020/02/12 20:38:45 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray.h"

void	ft_draw_help(t_info info)
{
	int x;
	int y;
	int color;

	y = 0;
	ft_recalculate(&info.cam->norm, &g_up, &g_right);
	while (y < info.res[1])
	{
		x = 0;
		while (x < info.res[0])
		{
			color = ft_intersect(x, y, info);
			info.mlx.img.data[y * info.res[0] + x] = color;
			x++;
		}
		y++;
	}
}

int		deal_key(int key, t_info *info)
{
	if (key == 124 && info->cam->next != NULL)
		info->cam = info->cam->next;
	if (key == 123 && info->cam->prev != NULL)
		info->cam = info->cam->prev;
	if (key == 123 || key == 124)
		ft_draw_help(*info);
	if (key == 53)
		ft_exit(info);
	mlx_put_image_to_window(info->mlx.mlx_ptr, info->mlx.win_ptr,
		info->mlx.img.img_ptr, 0, 0);
	return (0);
}

int		ft_exit(t_info *info)
{
	mlx_destroy_window(info->mlx.mlx_ptr, info->mlx.win_ptr);
	exit(0);
	return (0);
}

void	ft_draw(t_info info)
{
	info.mlx.mlx_ptr = mlx_init();
	info.mlx.win_ptr = mlx_new_window(info.mlx.mlx_ptr, info.res[0],
		info.res[1], "RT");
	info.mlx.img.img_ptr = mlx_new_image(info.mlx.mlx_ptr, info.res[0],
		info.res[1]);
	info.mlx.img.data = (int *)mlx_get_data_addr(info.mlx.img.img_ptr,
		&info.mlx.img.bpp, &info.mlx.img.size_l, &info.mlx.img.endian);
	mlx_key_hook(info.mlx.win_ptr, deal_key, &info);
	ft_draw_help(info);
	mlx_put_image_to_window(info.mlx.mlx_ptr, info.mlx.win_ptr,
		info.mlx.img.img_ptr, 0, 0);
	mlx_hook(info.mlx.win_ptr, 17, 0, ft_exit, &info);
	mlx_loop(info.mlx.mlx_ptr);
	exit(0);
}
