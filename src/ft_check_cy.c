/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cy_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 18:10:02 by ablanar           #+#    #+#             */
/*   Updated: 2019/12/30 17:56:35 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ray.h"

void	ft_cy_obs_help(t_cy *cy, double *a, t_vector *dl, t_info info)
{
	t_vector p;
	t_vector v;
	t_vector sqrt_a;
	t_vector sqrt_c;

	p = ft_vecsum(info.cam->o, dl[1]);
	v = dl[0];
	sqrt_a = ft_vsbst(v, ft_constmult(ft_dot_product(v, cy->norm), cy->norm));
	a[0] = ft_dot_product(sqrt_a, sqrt_a);
	sqrt_c = ft_vsbst(ft_vsbst(p, cy->coor),
	ft_constmult(ft_dot_product(ft_vsbst(p, cy->coor), cy->norm), cy->norm));
	a[1] = 2 * ft_dot_product(sqrt_a, sqrt_c);
	a[2] = ft_dot_product(sqrt_c, sqrt_c) - ((cy->d * cy->d) / 4);
}

int		ft_check_eq_sh(t_cy *cy, t_vector *ld, double t0, t_info info)
{
	t_vector pa1;
	t_vector pa2;
	t_vector q;

	q = ft_vecsum(ft_vecsum(ld[1], info.cam->o), ft_constmult(t0, ld[0]));
	pa1 = ft_vsbst(ft_vecsum(ft_vecsum(ld[1], info.cam->o), ft_constmult(t0,
		ld[0])), cy->coor);
	pa2 = ft_vsbst(ft_vecsum(ft_vecsum(ld[1], info.cam->o), ft_constmult(t0,
		ld[0])), ft_vecsum(cy->coor, ft_constmult(cy->h, cy->norm)));
	if (t0 < 1 + 1e-4 && t0 > 1e-3 && ft_dot_product(cy->norm, ft_vsbst(q,
		cy->coor)) >= 0 && ft_dot_product(cy->norm, ft_vsbst(q,
		ft_vecsum(cy->coor, ft_constmult(cy->h, cy->norm)))) <= 0)
		return (1);
	return (0);
}

int		ft_obs_cy(t_info info, t_cy *cy, t_vector l, t_vector d)
{
	double		k[2];
	double		a[3];
	t_vector	p[2];

	while (cy)
	{
		cy->norm = ft_normilize(cy->norm);
		p[0] = l;
		p[1] = d;
		ft_cy_obs_help(cy, &a[0], p, info);
		if (ft_solveq(a, &k[0], &k[1]))
		{
			if (k[0] > k[1])
				ft_swap(&k[0], &k[1]);
			if (k[0] < 0)
				k[0] = k[1];
			if (ft_check_eq_sh(cy, p, k[0], info))
				return (1);
			if (ft_check_eq_sh(cy, p, k[1], info))
				return (1);
		}
		cy = cy->next;
	}
	return (0);
}
