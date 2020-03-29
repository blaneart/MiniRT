/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inter_cu_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 16:21:36 by ablanar           #+#    #+#             */
/*   Updated: 2020/02/10 22:26:12 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ray.h"

t_cs	*ft_add_cs(t_cs **s, t_vector *c, float size, t_vector color)
{
	t_cs	*new;
	t_cs	*buf;

	if (!(new = malloc(sizeof(t_cs))))
		return (NULL);
	new->coor = c[0];
	new->size = size;
	new->norm = c[1];
	new->color = color;
	new->up = c[2];
	new->r = c[3];
	new->next = NULL;
	new->k = c;
	buf = *s;
	if (*s != NULL)
	{
		while ((*s)->next)
			(*s) = (*s)->next;
		(*s)->next = new;
		*s = buf;
		return (*s);
	}
	*s = new;
	return (*s);
}

void	ft_fill_cs(t_vector *c, t_vector norm, t_vector up, t_vector r)
{
	c[1] = norm;
	c[2] = up;
	c[3] = r;
}

void	ft_inter_sq_cu(t_vector d, t_info info, double *t, int *color)
{
	double		t0;
	t_cs		*cs;
	t_vector	cur;

	t0 = -1;
	cs = info.obj.cs;
	while (cs)
	{
		t0 = ft_dot_product(cs->norm, ft_vsbst(cs->coor, info.cam->o)) /
			ft_dot_product(cs->norm, d);
		cur = ft_vsbst(ft_constmult(t0, d), ft_vsbst(cs->coor, info.cam->o));
		if (t0 < *t && t0 > 0 && ft_abs(ft_dot_product(cur, cs->r)) < cs->size
			/ 2 && ft_abs(ft_dot_product(cur, cs->up)) < cs->size / 2)
		{
			*t = t0;
			*color = ft_shade_cu(info, ft_constmult(*t, d), cs);
		}
		cs = cs->next;
	}
}

void	ft_inter_cu(t_vector d, t_info info, double *t, int *color)
{
	t_cu		*cu;
	t_vector	s[2];
	t_cs		*buf;

	cu = info.obj.cu;
	info.obj.cs = NULL;
	while (cu)
	{
		ft_recalculate(&cu->norm, &s[0], &s[1]);
		ft_cu_help(&info.obj.cs, cu, s);
		ft_inter_sq_cu(d, info, t, color);
		while (info.obj.cs)
		{
			buf = info.obj.cs->next;
			free(info.obj.cs);
			info.obj.cs = buf;
		}
		info.obj.cs = NULL;
		cu = cu->next;
	}
}
