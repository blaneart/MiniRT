/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sq_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 18:36:37 by ablanar           #+#    #+#             */
/*   Updated: 2019/12/30 17:51:59 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray.h"

int	ft_obs_sq(t_info info, t_sq *sq, t_vector l, t_vector d)
{
	double		t0;
	t_vector	ur[2];
	t_vector	cur;

	while (sq)
	{
		ft_recalculate(&sq->norm, &ur[0], &ur[1]);
		t0 = -ft_dot_product(sq->norm, ft_vsbst(d, ft_vsbst(sq->coor,
			info.cam->o))) / ft_dot_product(sq->norm, l);
		cur = ft_vsbst(ft_constmult(t0, l), ft_vsbst(ft_vsbst(sq->coor,
			info.cam->o), d));
		if (t0 < 1 - 1e-6 && t0 > 1e-4 && ft_abs(ft_dot_product(cur, ur[0]))
		< sq->size / 2 && ft_abs(ft_dot_product(cur, ur[1])) < sq->size / 2)
			return (1);
		sq = sq->next;
	}
	return (0);
}
