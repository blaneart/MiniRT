/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectors1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:50:51 by ablanar           #+#    #+#             */
/*   Updated: 2019/12/30 17:53:17 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray.h"

t_vector	ft_constmult(double k, t_vector s)
{
	t_vector new;

	new.x = k * s.x;
	new.y = k * s.y;
	new.z = k * s.z;
	return (new);
}

double		ft_dot_product(t_vector s1, t_vector s2)
{
	return ((s1.x * s2.x) + (s1.y * s2.y) + (s1.z * s2.z));
}

double		ft_veclen(t_vector v)
{
	return (sqrt(ft_dot_product(v, v)));
}

t_vector	ft_vecsum(t_vector s1, t_vector s2)
{
	t_vector new;

	new.x = s1.x + s2.x;
	new.y = s1.y + s2.y;
	new.z = s1.z + s2.z;
	return (new);
}

t_vector	ft_vmult(t_vector s1, t_vector s2)
{
	t_vector new;

	new.x = (s1.y * s2.z - s1.z * s2.y);
	new.y = (s1.z * s2.x - s1.x * s2.z);
	new.z = (s1.x * s2.y - s1.y * s2.x);
	return (new);
}
