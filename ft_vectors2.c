/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectors2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:51:03 by ablanar           #+#    #+#             */
/*   Updated: 2019/12/30 17:53:23 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray.h"

t_vector	ft_vsbst(t_vector s1, t_vector s2)
{
	t_vector new;

	new.x = s1.x - s2.x;
	new.y = s1.y - s2.y;
	new.z = s1.z - s2.z;
	return (new);
}

t_vector	ft_inv(t_vector v)
{
	t_vector new;

	new.x = -v.x;
	new.y = -v.y;
	new.z = -v.z;
	return (new);
}

t_vector	ft_normilize(t_vector v)
{
	t_vector new;

	if (ft_veclen(v) > 1e-6)
	{
		new.x = v.x / ft_veclen(v);
		new.y = v.y / ft_veclen(v);
		new.z = v.z / ft_veclen(v);
	}
	else
	{
		new.x = 0;
		new.y = 0;
		new.z = 0;
	}
	return (new);
}

void		ft_fill_v(t_vector *v, float x, float y, float z)
{
	(*v).x = x;
	(*v).y = y;
	(*v).z = z;
}
