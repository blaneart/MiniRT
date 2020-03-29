/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inter_sq_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:49:21 by ablanar           #+#    #+#             */
/*   Updated: 2019/12/30 17:52:26 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray.h"

void	ft_inter_sq(t_vector d, t_info info, double *t, int *color)
{
	double		t0;
	t_sq		*sq;
	t_vector	ur[2];
	t_vector	cur;

	t0 = -1;
	sq = info.obj.sq;
	while (sq)
	{
		ft_recalculate(&sq->norm, &ur[0], &ur[1]);
		t0 = ft_dot_product(sq->norm, ft_vsbst(sq->coor, info.cam->o)) /
			ft_dot_product(sq->norm, d);
		cur = ft_vsbst(ft_constmult(t0, d), ft_vsbst(sq->coor, info.cam->o));
		if (t0 < *t && t0 > 0 && ft_abs(ft_dot_product(cur, ur[1])) < sq->size /
			2 && ft_abs(ft_dot_product(cur, ur[0])) < sq->size / 2)
		{
			*t = t0;
			*color = ft_shade_sq(info, ft_constmult(*t, d), sq);
		}
		sq = sq->next;
	}
}
