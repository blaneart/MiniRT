/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersect_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:49:37 by ablanar           #+#    #+#             */
/*   Updated: 2020/02/12 21:00:17 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray_bonus.h"

void	ft_recalculate(t_vector *norm, t_vector *ups, t_vector *rights)
{
	*norm = ft_normilize(*norm);
	ft_fill_v(ups, 0, 1, 0);
	*ups = ft_normilize(*ups);
	if ((*ups).x == (*norm).x && (*ups).y ==
		(*norm).y && (*ups).z == (*norm).z)
		ft_fill_v(&(*ups), 0, 0, -1);
	if ((*ups).x == (*norm).x && (*ups).y == -(*norm).y
		&& (*ups).z == (*norm).z)
		ft_fill_v(&(*ups), 0, 0, 1);
	*rights = ft_vmult(*ups, *norm);
	*rights = ft_normilize(*rights);
	*ups = ft_vmult(*norm, *rights);
	*rights = ft_normilize(*rights);
	*ups = ft_normilize(*ups);
}

void	ft_rotation(t_info info, t_vector *e, int x, int y)
{
	t_vector	stand;

	ft_fill_v(&stand, x - info.res[0] / 2, info.res[1] / 2 - y,
	-ft_d_count(info.res[1], info.cam->fov));
	e->x = ft_dot_product(g_right, stand) + info.cam->o.x;
	e->y = ft_dot_product(g_up, stand) + info.cam->o.y;
	e->z = ft_dot_product(ft_inv(info.cam->norm), stand) + info.cam->o.z;
}

int		ft_intersect(int x, int y, t_info info)
{
	double		t;
	int			color;
	t_vector	e;
	t_vector	dir;

	t = 10000000000000;
	color = 0;
	ft_rotation(info, &e, x, y);
	dir = ft_vsbst(e, info.cam->o);
	ft_inter_sp(dir, info, &t, &color);
	ft_inter_pl(dir, info, &t, &color);
	ft_inter_sq(dir, info, &t, &color);
	ft_inter_tr(dir, info, &t, &color);
	ft_inter_cy_ci(dir, info, &t, &color);
	ft_inter_cy(dir, info, &t, &color);
	ft_inter_cu(dir, info, &t, &color);
	return (color);
}
