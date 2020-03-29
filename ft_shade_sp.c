/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shade_sp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:50:31 by ablanar           #+#    #+#             */
/*   Updated: 2020/02/12 20:18:51 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray.h"

t_vector	ft_get_coef(t_vector c, t_vector l, t_vector norm, t_l *lt)
{
	norm = ft_normilize(norm);
	l = ft_normilize(l);
	c.x = c.x + (ft_dot_product(l, norm) * (lt->color.x / 255 * lt->b))
			/ ft_veclen(l) * ft_veclen(norm);
	c.y = c.y + (ft_dot_product(l, norm) * (lt->color.y / 255 * lt->b))
			/ ft_veclen(l) * ft_veclen(norm);
	c.z = c.z + (ft_dot_product(l, norm) * (lt->color.z / 255 * lt->b))
			/ ft_veclen(l) * ft_veclen(norm);
	return (c);
}

void		ft_zero_coef(t_vector *coef)
{
	if (coef->x < 0)
		coef->x = 0;
	if (coef->y < 0)
		coef->y = 0;
	if (coef->z < 0)
		coef->z = 0;
}

void		ft_get_spec(t_vector *coef, t_vector *ld, t_l *light, t_vector norm)
{
	norm = ft_normilize(norm);
	ld[0] = ft_normilize(ld[0]);
	ld[1] = ft_normilize(ld[1]);
	if (ft_veclen(ft_vsbst(ld[0], ld[1])) > 1e-4)
	{
		(*coef).x = (*coef).x + pow(ft_dot_product(ft_constmult(1 /
				ft_veclen(ft_vsbst(ld[0], ld[1])), ft_vsbst(ld[0], ld[1])),
				norm), 100) * light->color.x;
		(*coef).y = (*coef).y + pow(ft_dot_product(ft_constmult(1 /
				ft_veclen(ft_vsbst(ld[0], ld[1])), ft_vsbst(ld[0], ld[1])),
				norm), 100) * light->color.y;
		(*coef).z = (*coef).z + pow(ft_dot_product(ft_constmult(1 /
				ft_veclen(ft_vsbst(ld[0], ld[1])), ft_vsbst(ld[0], ld[1])),
				norm), 100) * light->color.z;
	}
	else
		ft_fill_v(coef, 1, 1, 1);
}

int			ft_color(t_vector *coef, t_vector color, t_info info)
{
	int		r[3];

	r[0] = (info.al.r * (info.al.color.x / 255) + coef[0].x) *
	1.5 * color.x + coef[1].x * 0.4;
	r[1] = (info.al.r * (info.al.color.y / 255) + coef[0].y) *
	1.5 * color.y + coef[1].y * 0.4;
	r[2] = (info.al.r * (info.al.color.z / 255) + coef[0].z) *
	1.5 * color.z + coef[1].z * 0.4;
	if (r[0] > 255 || r[0] < 0)
		r[0] = r[0] < 0 ? 0 : 255;
	if (r[1] > 255 || r[1] < 0)
		r[1] = r[1] < 0 ? 0 : 255;
	if (r[2] > 255 || r[2] < 0)
		r[2] = r[2] < 0 ? 0 : 255;
	return ((r[0] << 16) + (r[1] << 8) + r[2]);
}

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
