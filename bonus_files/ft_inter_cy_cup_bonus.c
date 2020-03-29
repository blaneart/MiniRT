/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inter_cy_cup_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:48:56 by ablanar           #+#    #+#             */
/*   Updated: 2020/02/12 16:11:27 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray_bonus.h"

double	ft_check_ci(t_info info, t_cy *cy, t_vector d, double t0)
{
	t_vector pa1;

	pa1 = ft_vsbst(ft_constmult(t0, d), ft_vsbst(cy->coor, info.cam->o));
	if (ft_abs(ft_dot_product(cy->norm, pa1)) < 1e-4 && ft_dot_product(pa1, pa1)
			< cy->d * cy->d / 4)
		return (1);
	return (0);
}

double	ft_check_ci_d(t_info info, t_cy *cy, double t0, t_vector d)
{
	t_vector pa2;

	pa2 = ft_vsbst(ft_constmult(t0, d), ft_vecsum(ft_vsbst(cy->coor,
		info.cam->o), ft_constmult(cy->h, cy->norm)));
	if (ft_abs(ft_dot_product(cy->norm, pa2)) < 1e-4 && ft_dot_product(pa2, pa2)
			< cy->d * cy->d / 4)
		return (1);
	return (0);
}

void	ft_inter_cy_ci(t_vector d, t_info info, double *t, int *color)
{
	t_cy	*cy;
	double	t0;
	double	t1;

	cy = info.obj.cy;
	while (cy)
	{
		cy->norm = ft_normilize(cy->norm);
		t0 = ft_dot_product(cy->norm, ft_vsbst(cy->coor, info.cam->o)) /
				ft_dot_product(d, cy->norm);
		t1 = ft_dot_product(cy->norm, ft_vecsum(ft_constmult(cy->h, cy->norm),
				ft_vsbst(cy->coor, info.cam->o))) / ft_dot_product(d, cy->norm);
		if (ft_check_ci(info, cy, d, t0) && t0 < *t && t0 > 0)
		{
			*t = t0;
			*color = ft_shade_cy_ci(info, ft_constmult(*t, d), cy);
		}
		if (ft_check_ci_d(info, cy, t1, d) && t1 < *t && t1 > 0)
		{
			*t = t1;
			*color = ft_shade_cy_ci(info, ft_constmult(*t, d), cy);
		}
		cy = cy->next;
	}
}
