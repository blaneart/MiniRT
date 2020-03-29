/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inter_pl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:49:02 by ablanar           #+#    #+#             */
/*   Updated: 2019/12/24 12:58:15 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray.h"

void	ft_inter_pl(t_vector d, t_info info, double *t, int *color)
{
	t_pl	*pl;
	double	t0;

	pl = info.obj.pl;
	while (pl)
	{
		pl->norm = ft_normilize(pl->norm);
		t0 = ft_dot_product(pl->norm, ft_vsbst(pl->coor, info.cam->o)) /
			ft_dot_product(pl->norm, d);
		if (t0 > 0)
		{
			if (t0 < *t && t0 > 0)
			{
				*t = t0;
				*color = ft_shade_pl(info, ft_constmult(*t, d), pl);
			}
		}
		pl = pl->next;
	}
}
