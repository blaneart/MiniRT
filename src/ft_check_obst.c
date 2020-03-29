/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_obst_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:46:32 by ablanar           #+#    #+#             */
/*   Updated: 2019/12/30 17:12:05 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ray.h"

int		ft_tr_obs_helper(t_tr *tr, t_info info, t_vector *dl, double t0)
{
	t_vector abc[3];
	t_vector vec[3];

	abc[0] = ft_vsbst(tr->c[1], tr->c[0]);
	abc[1] = ft_vsbst(tr->c[2], tr->c[1]);
	abc[2] = ft_vsbst(tr->c[0], tr->c[2]);
	vec[0] = ft_vmult(abc[0], ft_vsbst(tr->c[0], ft_vecsum(ft_constmult(t0,
			dl[1]), ft_vecsum(dl[0], info.cam->o))));
	vec[1] = ft_vmult(abc[1], ft_vsbst(tr->c[1],
			ft_vecsum(ft_constmult(t0, dl[1]),
			ft_vecsum(dl[0], info.cam->o))));
	vec[2] = ft_vmult(abc[2], ft_vsbst(tr->c[2],
			ft_vecsum(ft_constmult(t0, dl[1]),
			ft_vecsum(dl[0], info.cam->o))));
	if (ft_dot_product(vec[0], vec[1]) >= 0 && ft_dot_product(vec[1], vec[2])
		>= 0 && ft_dot_product(vec[2], vec[0]) >= 0)
		return (1);
	return (0);
}

int		ft_obs_tr(t_info info, t_tr *tr, t_vector l, t_vector d)
{
	double		t0;
	t_vector	norm;
	t_vector	help[2];

	while (tr)
	{
		norm = ft_vmult(ft_vsbst(tr->c[1], tr->c[0]), ft_vsbst(tr->c[2],
				tr->c[1]));
		t0 = ft_dot_product(norm, ft_vsbst(tr->c[2], ft_vecsum(d, info.cam->o)))
			/ ft_dot_product(norm, l);
		help[0] = d;
		help[1] = l;
		if (t0 > 1e-4 && t0 < 1 - 1e-4 && ft_tr_obs_helper(tr, info, help, t0))
			return (1);
		tr = tr->next;
	}
	return (0);
}

int		ft_check_obst(t_info info, t_vector l, t_vector d)
{
	if (ft_obs_tr(info, info.obj.tr, l, d))
		return (1);
	if (ft_obs_sp(info, info.obj.sp, l, d))
		return (1);
	if (ft_obs_pl(info, info.obj.pl, l, d))
		return (1);
	if (ft_obs_sq(info, info.obj.sq, l, d))
		return (1);
	if (ft_obs_cy(info, info.obj.cy, l, d))
		return (1);
	if (ft_obs_cu(info, info.obj.cu, l, d))
		return (1);
	if (ft_obs_cy_cup(info, info.obj.cy, l, d))
		return (1);
	return (0);
}
