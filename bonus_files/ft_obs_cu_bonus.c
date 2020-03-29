/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obs_cu_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 14:46:06 by ablanar           #+#    #+#             */
/*   Updated: 2019/12/30 17:12:25 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray_bonus.h"

int		ft_shade_sq_cu(t_info info, t_cs *cs, t_vector l, t_vector d)
{
	double		t0;
	t_vector	cur;
	t_cs		*buf;

	buf = cs;
	while (buf)
	{
		t0 = -ft_dot_product(buf->norm, ft_vsbst(d, ft_vsbst(buf->coor,
				info.cam->o))) / ft_dot_product(buf->norm, l);
		cur = ft_vsbst(ft_constmult(t0, l), ft_vsbst(ft_vsbst(buf->coor,
				info.cam->o), d));
		if (t0 < 1 - 1e-4 && t0 > 1e-3 && ft_abs(ft_dot_product(cur, buf->r))
			< buf->size / 2 && ft_abs(ft_dot_product(cur, buf->up))
				< buf->size / 2)
			return (1);
		buf = buf->next;
	}
	while (cs)
	{
		buf = cs->next;
		free(cs);
		cs = buf;
	}
	cs = NULL;
	return (0);
}

void	ft_free_cs(t_cs **cs)
{
	t_cs	*buf;

	if ((*cs))
	{
		while (*cs)
		{
			buf = (*cs)->next;
			free(*cs);
			*cs = buf;
		}
		*cs = NULL;
	}
}

void	ft_cu_help(t_cs **cs, t_cu *cu, t_vector *s)
{
	t_vector	kek[4];

	ft_fill_cs(kek, cu->norm, s[0], s[1]);
	kek[0] = ft_vecsum(cu->coor, ft_constmult(cu->size / 2, cu->norm));
	ft_add_cs(cs, kek, cu->size, cu->color);
	ft_fill_cs(kek, ft_inv(cu->norm), s[0], s[1]);
	kek[0] = ft_vecsum(cu->coor, ft_constmult(-cu->size / 2, cu->norm));
	ft_add_cs(cs, kek, cu->size, cu->color);
	ft_fill_cs(kek, s[0], s[1], cu->norm);
	kek[0] = ft_vecsum(cu->coor, ft_constmult(cu->size / 2, s[0]));
	ft_add_cs(cs, kek, cu->size, cu->color);
	ft_fill_cs(kek, ft_inv(s[0]), s[1], cu->norm);
	kek[0] = ft_vecsum(cu->coor, ft_constmult(-cu->size / 2, s[0]));
	ft_add_cs(cs, kek, cu->size, cu->color);
	ft_fill_cs(kek, s[1], s[0], cu->norm);
	kek[0] = ft_vecsum(cu->coor, ft_constmult(cu->size / 2, s[1]));
	ft_add_cs(cs, kek, cu->size, cu->color);
	ft_fill_cs(kek, ft_inv(s[1]), s[0], cu->norm);
	kek[0] = ft_vecsum(cu->coor, ft_constmult(-cu->size / 2, s[1]));
	ft_add_cs(cs, kek, cu->size, cu->color);
}

int		ft_obs_cu(t_info info, t_cu *cu, t_vector l, t_vector d)
{
	t_vector	s[2];
	t_cs		*cs;

	cs = NULL;
	while (cu)
	{
		ft_recalculate(&cu->norm, &s[0], &s[1]);
		ft_cu_help(&cs, cu, s);
		if (ft_shade_sq_cu(info, cs, l, d))
		{
			ft_free_cs(&cs);
			return (1);
		}
		cu = cu->next;
	}
	return (0);
}
