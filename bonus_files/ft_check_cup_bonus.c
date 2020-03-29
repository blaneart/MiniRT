/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cup_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 12:47:52 by ablanar           #+#    #+#             */
/*   Updated: 2020/01/02 15:11:05 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray_bonus.h"

double	ft_check_ci_sh(t_info info, t_cy *cy, t_vector *ld, double t0)
{
	t_vector pa1;

	pa1 = ft_vsbst(ft_vecsum(ft_vecsum(info.cam->o, ld[1]),
			ft_constmult(t0, ld[0])), cy->coor);
	if (ft_abs(ft_dot_product(cy->norm, pa1)) < 1e-4 && ft_dot_product(pa1, pa1)
			< cy->d * cy->d / 4)
		return (1);
	return (0);
}

double	ft_check_ci_sh_d(t_info info, t_cy *cy, t_vector *ld, double t0)
{
	t_vector pa2;

	pa2 = ft_vsbst(ft_vecsum(ft_vecsum(info.cam->o, ld[1]), ft_constmult(t0,
			ld[0])), ft_vecsum(cy->coor, ft_constmult(t0, cy->norm)));
	if (ft_abs(ft_dot_product(cy->norm, pa2)) < 1e-4 && ft_dot_product(pa2, pa2)
			< cy->d * cy->d / 4)
		return (1);
	return (0);
}

int		ft_obs_cy_cup(t_info info, t_cy *cy, t_vector l, t_vector d)
{
	double		t0;
	double		t1;
	t_vector	ld[2];

	ld[0] = l;
	ld[1] = d;
	while (cy)
	{
		cy->norm = ft_normilize(cy->norm);
		t0 = ft_dot_product(cy->norm, ft_vsbst(cy->coor, ft_vecsum(info.cam->o,
				d))) / ft_dot_product(cy->norm, l);
		t1 = -ft_dot_product(cy->norm, ft_vsbst(d, ft_vecsum(ft_vsbst(cy->coor,
				info.cam->o), ft_constmult(cy->h, cy->norm)))) /
				ft_dot_product(l, (cy->norm));
		if (ft_check_ci_sh(info, cy, ld, t0) && t0 < 1 && t0 > 1e-4)
			return (1);
		if (ft_check_ci_sh_d(info, cy, ld, t1) && t1 < 1 && t1 > 1e-4)
			return (1);
		cy = cy->next;
	}
	return (0);
}
