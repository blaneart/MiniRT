/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sp_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 18:36:28 by ablanar           #+#    #+#             */
/*   Updated: 2019/12/30 18:01:32 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray.h"

int		ft_obs_sp(t_info info, t_sp *sp, t_vector l, t_vector d)
{
	t_vector	dot;
	double		a[3];
	double		k[2];

	dot = ft_vecsum(d, info.cam->o);
	k[1] = -1;
	k[0] = -1;
	while (sp)
	{
		a[0] = ft_dot_product(l, l);
		a[1] = 2 * (ft_dot_product(l, ft_vsbst(dot, sp->coor)));
		a[2] = ft_dot_product(ft_vsbst(sp->coor, dot), ft_vsbst(sp->coor, dot))
			- sp->r * sp->r;
		if (ft_solveq(a, &k[0], &k[1]))
		{
			if (k[0] > k[1] - 1e-4)
				ft_swap(&k[0], &k[1]);
			if (k[0] < 1e-4)
				k[0] = k[1];
			if (k[0] < 1 - 1e-4 && k[0] > 1e-4)
				return (1);
		}
		sp = sp->next;
	}
	return (0);
}
