/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inter_cy_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:48:56 by ablanar           #+#    #+#             */
/*   Updated: 2019/12/30 17:56:45 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ray.h"

int		ft_check_eq(t_info info, t_cy *cy, t_vector d, double t0)
{
	t_vector pa1;
	t_vector pa2;

	pa1 = ft_vsbst(ft_constmult(t0, d), ft_vsbst(cy->coor, info.cam->o));
	pa2 = ft_vsbst(ft_constmult(t0, d), ft_vecsum(ft_vsbst(cy->coor,
		info.cam->o), ft_constmult(cy->h, cy->norm)));
	if (ft_dot_product(cy->norm, pa1) > 0
		&& ft_dot_product(cy->norm, pa2) < 0)
		return (1);
	return (0);
}

void	ft_cy_help(t_cy *cy, double *a, t_vector d, t_info info)
{
	a[0] = ft_dot_product(ft_vsbst(d, ft_constmult(ft_dot_product(d, cy->norm),
		cy->norm)), ft_vsbst(d, ft_constmult(ft_dot_product(d, cy->norm),
		cy->norm)));
	a[1] = 2 * ft_dot_product(ft_vsbst(d, ft_constmult(ft_dot_product(d,
		cy->norm), cy->norm)), ft_vsbst(ft_vsbst(info.cam->o, cy->coor),
		ft_constmult(ft_dot_product(ft_vsbst(info.cam->o, cy->coor),
		cy->norm), cy->norm)));
	a[2] = ft_dot_product(ft_vsbst(ft_vsbst(info.cam->o, cy->coor),
	ft_constmult(ft_dot_product(ft_vsbst(info.cam->o, cy->coor), cy->norm),
	cy->norm)), ft_vsbst(ft_vsbst(info.cam->o, cy->coor),
	ft_constmult(ft_dot_product(ft_vsbst(info.cam->o, cy->coor), cy->norm),
	cy->norm))) - (cy->d * cy->d) / 4;
}

void	ft_inter_cy(t_vector d, t_info info, double *t, int *color)
{
	t_cy	*cy;
	double	k[2];
	double	a[3];

	cy = info.obj.cy;
	while (cy)
	{
		cy->norm = ft_normilize(cy->norm);
		ft_cy_help(cy, &a[0], d, info);
		if (ft_solveq(a, &k[0], &k[1]))
		{
			if (ft_check_eq(info, cy, d, k[0]) && k[0] < *t && k[0] > 0)
			{
				*t = k[0];
				*color = ft_shade_cy(info, ft_constmult(*t, d), cy);
			}
			else if (ft_check_eq(info, cy, d, k[1]) && k[1] < *t && k[1] > 0)
			{
				*t = k[1];
				*color = ft_shade_cy_beh(info, ft_constmult(*t, d), cy);
			}
		}
		cy = cy->next;
	}
}
