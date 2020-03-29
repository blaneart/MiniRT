/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:46:22 by ablanar           #+#    #+#             */
/*   Updated: 2019/12/23 17:33:15 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray.h"

double		ft_to_radiant(float degree)
{
	return ((degree * M_PI) / 180);
}

double		ft_abs(double a)
{
	if (a < 0)
		return (-a);
	return (a);
}

double		ft_d_count(int h, float fov)
{
	return (h / (2 * tan(ft_to_radiant(fov / 2))));
}

void		ft_swap(double *a, double *b)
{
	double buf;

	buf = *a;
	*a = *b;
	*b = buf;
}

int			ft_solveq(double *a, double *x0, double *x1)
{
	double discr;
	double q;

	discr = a[1] * a[1] - 4 * a[0] * a[2];
	if (discr < 0)
		return (0);
	else if (discr == 0)
	{
		*x0 = ((-0.5 * a[1]) / a[0]);
		*x1 = ((-0.5 * a[1]) / a[0]);
	}
	else
	{
		q = (a[1] > 0) ?
			-0.5 * (a[1] + sqrt(discr)) :
			-0.5 * (a[1] - sqrt(discr));
		*x0 = q / a[0];
		*x1 = a[2] / q;
	}
	if (*x0 > *x1)
		ft_swap(x0, x1);
	if (*x0 < 0)
		ft_swap(x0, x1);
	return (1);
}
