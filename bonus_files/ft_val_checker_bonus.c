/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_checker_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:42:09 by ablanar           #+#    #+#             */
/*   Updated: 2020/02/11 14:42:31 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray_bonus.h"

int		ft_check_cy_val(t_cy *cy)
{
	while (cy != NULL)
	{
		if (cy->h <= 0 || cy->d <= 0)
			return (-1);
		if (ft_check_norm_val(cy->norm) == -1 ||
			ft_check_color_val(cy->color) == -1)
			return (-1);
		cy = cy->next;
	}
	return (1);
}

int		ft_check_tr_val(t_tr *tr)
{
	while (tr != NULL)
	{
		if (ft_check_color_val(tr->color) == -1)
			return (-1);
		tr = tr->next;
	}
	return (1);
}

int		ft_check_cu_val(t_cu *cu)
{
	while (cu != NULL)
	{
		if (cu->size <= 0)
			return (-1);
		if (ft_check_color_val(cu->color) == -1)
			return (-1);
		if (ft_check_norm_val(cu->norm) == -1)
			return (-1);
		cu = cu->next;
	}
	return (1);
}

int		ft_check_obj_val(t_obj obj)
{
	if (ft_check_sp_val(obj.sp) == -1 || ft_check_pl_val(obj.pl) == -1 ||
		ft_check_sq_val(obj.sq) == -1 || ft_check_tr_val(obj.tr) == -1 ||
		ft_check_cy_val(obj.cy) == -1 || ft_check_cu_val(obj.cu) == -1)
		return (-1);
	else
		return (1);
}

int		ft_check_lights_val(t_l *lights)
{
	while (lights != NULL)
	{
		if (lights->b < 0.00000000 || lights->b > 1.00000000)
			return (-1);
		if (ft_check_color_val(lights->color) == -1)
			return (-1);
		lights = lights->next;
	}
	return (1);
}
