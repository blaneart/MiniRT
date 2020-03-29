/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inter_tr_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:49:29 by ablanar           #+#    #+#             */
/*   Updated: 2019/12/30 17:52:30 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ray.h"

int		ft_tr_helper(t_tr *tr, t_info info, t_vector d, double t0)
{
	t_vector abc[3];
	t_vector vec[3];

	abc[0] = ft_vsbst(tr->c[1], tr->c[0]);
	abc[1] = ft_vsbst(tr->c[2], tr->c[1]);
	abc[2] = ft_vsbst(tr->c[0], tr->c[2]);
	vec[0] = ft_vmult(abc[0], ft_vsbst(tr->c[0], ft_vecsum(info.cam->o,
		ft_constmult(t0, d))));
	vec[1] = ft_vmult(abc[1], ft_vsbst(tr->c[1], ft_vecsum(info.cam->o,
		ft_constmult(t0, d))));
	vec[2] = ft_vmult(abc[2], ft_vsbst(tr->c[2], ft_vecsum(info.cam->o,
		ft_constmult(t0, d))));
	if (ft_dot_product(vec[0], vec[1]) >= 0 && ft_dot_product(vec[1], vec[2])
		>= 0 && ft_dot_product(vec[2], vec[0]) >= 0)
		return (1);
	return (0);
}

void	ft_inter_tr(t_vector d, t_info info, double *t, int *color)
{
	t_tr		*tr;
	double		t0;
	t_vector	norm;

	tr = info.obj.tr;
	while (tr)
	{
		norm = ft_vmult(ft_vsbst(tr->c[1], tr->c[0]),
		ft_vsbst(tr->c[2], tr->c[1]));
		norm = ft_normilize(norm);
		t0 = ft_dot_product(norm, ft_vsbst(tr->c[0], info.cam->o)) /
		ft_dot_product(norm, d);
		if (t0 > 0 && t0 < *t && ft_tr_helper(tr, info, d, t0))
		{
			*t = t0;
			*color = ft_shade_tr(info, ft_constmult(*t, d), tr, norm);
		}
		tr = tr->next;
	}
}
