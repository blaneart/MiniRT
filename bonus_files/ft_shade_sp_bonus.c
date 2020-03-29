/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shade_sp_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:50:31 by ablanar           #+#    #+#             */
/*   Updated: 2020/02/12 19:57:14 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray_bonus.h"

int			ft_shade_sp(t_info info, t_vector d, t_sp *sp)
{
	t_vector		l[2];
	t_l				*light;
	t_vector		norm;
	t_vector		coef[2];

	ft_fill_v(&coef[0], 0, 0, 0);
	ft_fill_v(&coef[1], 0, 0, 0);
	light = info.l;
	l[1] = d;
	while (light)
	{
		l[0] = ft_vsbst(light->coor, ft_vecsum(d, info.cam->o));
		norm = ft_normilize(ft_vsbst(d, ft_vsbst(sp->coor, info.cam->o)));
		if (ft_dot_product(norm, info.cam->norm) > 0)
			norm = ft_inv(norm);
		if (ft_check_obst(info, l[0], d) == 0 && ft_dot_product(l[0], norm) > 0)
		{
			coef[0] = ft_get_coef(coef[0], l[0], norm, light);
			ft_get_spec(&coef[1], l, light, norm);
		}
		light = light->next;
	}
	return (ft_color(coef, sp->color, info));
}
