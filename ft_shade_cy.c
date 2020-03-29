/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shade_cy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:50:12 by ablanar           #+#    #+#             */
/*   Updated: 2020/02/12 16:47:05 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray.h"

int	ft_shade_cy(t_info info, t_vector d, t_cy *cy)
{
	t_vector	l[2];
	t_l			*lt;
	t_vector	n[2];
	t_vector	c[2];

	ft_fill_v(&c[0], 0, 0, 0);
	ft_fill_v(&c[1], 0, 0, 0);
	lt = info.l;
	l[1] = d;
	while (lt)
	{
		n[1] = ft_vsbst(d, ft_vsbst(cy->coor, info.cam->o));
		n[0] = ft_vsbst(n[1], ft_constmult(ft_dot_product(n[1],
			cy->norm), cy->norm));
		if (ft_dot_product(n[0], info.cam->norm) >= 0)
			n[0] = ft_inv(n[0]);
		l[0] = ft_vsbst(lt->coor, ft_vecsum(d, info.cam->o));
		if (ft_dot_product(l[0], n[0]) > 1e-2 && !ft_check_obst(info, l[0], d))
		{
			c[0] = ft_get_coef(c[0], l[0], n[0], lt);
			ft_get_spec(&c[1], l, lt, n[0]);
		}
		lt = lt->next;
	}
	return (ft_color(c, cy->color, info));
}

int	ft_shade_cy_beh(t_info info, t_vector d, t_cy *cy)
{
	t_vector	l[2];
	t_l			*lt;
	t_vector	n[2];
	t_vector	c[2];

	ft_fill_v(&c[0], 0, 0, 0);
	ft_fill_v(&c[1], 0, 0, 0);
	lt = info.l;
	l[1] = d;
	while (lt)
	{
		n[1] = ft_vsbst(d, ft_vsbst(cy->coor, info.cam->o));
		n[0] = ft_inv(ft_vsbst(n[1], ft_constmult(ft_dot_product(n[1],
					cy->norm), cy->norm)));
		l[0] = ft_vsbst(lt->coor, ft_vecsum(d, info.cam->o));
		if (ft_dot_product(l[0], n[0]) > 1e-2 && !ft_check_obst(info, l[0], d))
		{
			c[0] = ft_get_coef(c[0], l[0], n[0], lt);
			ft_get_spec(&c[1], l, lt, *n);
		}
		lt = lt->next;
	}
	return (ft_color(c, cy->color, info));
}
