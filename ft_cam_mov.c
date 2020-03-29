/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cam_mov_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:26:50 by ablanar           #+#    #+#             */
/*   Updated: 2020/02/12 16:36:07 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray.h"

void	ft_calcul_norm_l(t_info *info)
{
	if ((*info).cam->norm.z > -0.01)
		(*info).cam->norm.x = (*info).cam->norm.x - 0.1;
	else
		(*info).cam->norm.x = (*info).cam->norm.x + 0.1;
	if ((*info).cam->norm.x < -0.99 && (*info).cam->norm.x < 0.01)
		(*info).cam->norm.z = -0.1;
	else if ((*info).cam->norm.x > 0.99 && (*info).cam->norm.x > -0.01)
		(*info).cam->norm.z = 0.1;
	else if ((*info).cam->norm.z < 0.01)
		(*info).cam->norm.z = -1 * sqrtf(1 - powf((*info).cam->norm.x, 2)
				- powf((*info).cam->norm.y, 2));
	else if ((*info).cam->norm.z > -0.01)
		(*info).cam->norm.z = sqrtf(1 - powf((*info).cam->norm.x, 2)
				- powf((*info).cam->norm.y, 2));
}

void	ft_calcul_norm_r(t_info *info)
{
	if ((*info).cam->norm.z > -0.01)
		(*info).cam->norm.x = (*info).cam->norm.x + 0.1;
	else
		(*info).cam->norm.x = (*info).cam->norm.x - 0.1;
	if ((*info).cam->norm.x < -0.99 && (*info).cam->norm.x < 0.01)
		(*info).cam->norm.z = 0.1;
	else if ((*info).cam->norm.x > 0.99 && (*info).cam->norm.x > -0.01)
		(*info).cam->norm.z = -0.1;
	else if ((*info).cam->norm.z < 0.01)
		(*info).cam->norm.z = -1 * sqrtf(1 - powf((*info).cam->norm.x, 2)
				- powf((*info).cam->norm.y, 2));
	else if ((*info).cam->norm.z > -0.01)
		(*info).cam->norm.z = sqrtf(1 - powf((*info).cam->norm.x, 2)
				- powf((*info).cam->norm.y, 2));
}

void	ft_calcul_norm_u(t_info *info)
{
	if ((*info).cam->norm.z > -0.01 && !((*info).cam->norm.y > 0.99))
		(*info).cam->norm.y = (*info).cam->norm.y + 0.1;
	else
		(*info).cam->norm.y = (*info).cam->norm.y - 0.1;
	if ((*info).cam->norm.y < -0.99)
		(*info).cam->norm.z = -0.1;
	else if ((*info).cam->norm.y > 0.99)
		(*info).cam->norm.z = 0.1;
	else if ((*info).cam->norm.z > -0.01)
		(*info).cam->norm.z = 1 * sqrtf(1 - powf((*info).cam->norm.y, 2)
				- powf((*info).cam->norm.x, 2));
	else if ((*info).cam->norm.z < 0.01)
		(*info).cam->norm.z = -1 * sqrtf(1 - powf((*info).cam->norm.y, 2)
				- powf((*info).cam->norm.x, 2));
}

void	ft_calcul_norm_d(t_info *info)
{
	if ((*info).cam->norm.z > -0.01)
		(*info).cam->norm.y = (*info).cam->norm.y - 0.1;
	else
		(*info).cam->norm.y = (*info).cam->norm.y + 0.1;
	if ((*info).cam->norm.y < -0.99 && (*info).cam->norm.y < 0.01)
		(*info).cam->norm.z = -0.1;
	else if ((*info).cam->norm.y > 0.99 && (*info).cam->norm.y > -0.01)
		(*info).cam->norm.z = 0.1;
	else if ((*info).cam->norm.z < 0.01)
		(*info).cam->norm.z = -1 * sqrtf(1 - powf((*info).cam->norm.y, 2)
				- powf((*info).cam->norm.x, 2));
	else if ((*info).cam->norm.z > -0.01)
		(*info).cam->norm.z = sqrtf(1 - powf((*info).cam->norm.y, 2)
				- powf((*info).cam->norm.x, 2));
}

int		deal_mouse(int b, int x, int y, t_info *info)
{
	(void)b;
	if (x < (*info).res[0] / 3)
		ft_calcul_norm_l(info);
	if (x > (*info).res[0] * 2 / 3)
		ft_calcul_norm_r(info);
	if (y < (*info).res[1] / 3)
		ft_calcul_norm_u(info);
	if (y > (*info).res[1] * 2 / 3)
		ft_calcul_norm_d(info);
	ft_draw_help(*info);
	mlx_put_image_to_window(info->mlx.mlx_ptr, info->mlx.win_ptr,
		info->mlx.img.img_ptr, 0, 0);
	return (0);
}
