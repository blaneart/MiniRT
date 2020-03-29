/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_with_threads.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:46:40 by ablanar           #+#    #+#             */
/*   Updated: 2020/02/12 21:29:06 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray.h"

void	*ft_thread(void *threadarg)
{
	long			x;
	long			y;
	int				color;
	t_thread_data	*my_data;

	my_data = (t_thread_data *)threadarg;
	y = 0;
	while (y < my_data->info->res[1])
	{
		x = my_data->thread_id;
		while (x < my_data->info->res[0])
		{
			color = ft_intersect(x, y, *my_data->info);
			my_data->info->mlx.img.data[y * my_data->info->res[0] + x] = color;
			x = x + 8;
		}
		y++;
	}
	return (NULL);
}

void	ft_draw_help(t_info info)
{
	pthread_t		threads[8];
	long			t;
	t_thread_data	data_array[8];
	void			*status;
	pthread_attr_t	attr;

	t = 0;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	ft_recalculate(&info.cam->norm, &g_up, &g_right);
	while (t < 8)
	{
		data_array[t].thread_id = t;
		data_array[t].info = &info;
		pthread_create(&threads[t], NULL, ft_thread, (void *)&data_array[t]);
		t++;
	}
	t = 0;
	pthread_attr_destroy(&attr);
	while (t < 8)
	{
		pthread_join(threads[t], &status);
		t++;
	}
}

int		deal_key(int key, t_info *info)
{
	if (key == 0 || key == 1 || key == 2 || key == 13 || key == 12 || key == 14)
	{
		ft_change_cam(&info->cam, key);
		ft_draw_help(*info);
	}
	if (key == 124 && info->cam->next != NULL)
		info->cam = info->cam->next;
	if (key == 123 && info->cam->prev != NULL)
		info->cam = info->cam->prev;
	if (key == 123 || key == 124)
		ft_draw_help(*info);
	if (key == 53)
		ft_exit(info);
	if (key == 3)
	{
		(*info).filter = (*info).filter == 1 ? 0 : 1;
		ft_draw_help(*info);
	}
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
	mlx_mouse_hook(info.mlx.win_ptr, deal_mouse, &info);
	ft_draw_help(info);
	mlx_put_image_to_window(info.mlx.mlx_ptr, info.mlx.win_ptr,
		info.mlx.img.img_ptr, 0, 0);
	mlx_hook(info.mlx.win_ptr, 17, 0, ft_exit, &info);
	mlx_loop(info.mlx.mlx_ptr);
	exit(0);
}
