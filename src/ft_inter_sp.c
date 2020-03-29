/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inter_sp_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:49:16 by ablanar           #+#    #+#             */
/*   Updated: 2019/12/30 17:52:22 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ray.h"

void	ft_sp_help(t_info info, t_vector d, t_sp *sp, double *a)
{
	a[0] = ft_dot_product(d, d);
	a[1] = 2 * (ft_dot_product(d, ft_vsbst(info.cam->o, sp->coor)));
	a[2] = ft_dot_product(ft_vsbst(info.cam->o, sp->coor), ft_vsbst(info.cam->o,
		sp->coor)) - sp->r * sp->r;
}

void	ft_inter_sp(t_vector d, t_info info, double *t, int *color)
{
	t_sp	*sp;
	double	t0;
	double	t1;
	double	a[3];

	sp = info.obj.sp;
	t0 = -1;
	t1 = -1;
	while (sp)
	{
		ft_sp_help(info, d, sp, &a[0]);
		if (ft_solveq(a, &t0, &t1))
		{
			if (t0 > t1)
				ft_swap(&t0, &t1);
			if (t0 < 0)
				t0 = t1;
			if (t0 < *t && t0 >= 0)
			{
				*t = t0;
				*color = ft_shade_sp(info, ft_constmult(*t, d), sp);
			}
		}
		sp = sp->next;
	}
}
