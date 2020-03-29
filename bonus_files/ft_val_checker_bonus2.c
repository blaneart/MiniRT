/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_checker_bonus2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:42:58 by ablanar           #+#    #+#             */
/*   Updated: 2020/02/11 14:49:43 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray_bonus.h"

int		ft_check_inp(t_info info)
{
	if (info.cam == NULL || info.res[0] < 0 || info.res[1] < 0)
	{
		write(2, "Error\nMistake in the scene file\n", 32);
		return (-1);
	}
	return (1);
}

int		ft_check_sp_val(t_sp *sp)
{
	while (sp != NULL)
	{
		if (sp->r <= 0)
			return (-1);
		if (ft_check_color_val(sp->color) == -1)
			return (-1);
		sp = sp->next;
	}
	return (1);
}

int		ft_check_pl_val(t_pl *pl)
{
	while (pl != NULL)
	{
		if (ft_check_norm_val(pl->norm) == -1 ||
			ft_check_color_val(pl->color) == -1)
			return (-1);
		pl = pl->next;
	}
	return (1);
}

int		ft_check_sq_val(t_sq *sq)
{
	while (sq != NULL)
	{
		if (sq->size <= 0)
			return (-1);
		if (ft_check_norm_val(sq->norm) == -1 ||
			ft_check_color_val(sq->color) == -1)
			return (-1);
		sq = sq->next;
	}
	return (1);
}

int		ft_check_objects_val(t_info *info)
{
	if ((*info).res[0] <= 0 || (*info).res[1] <= 0)
		return (-1);
	if ((*info).res[0] > 2560)
		(*info).res[0] = 2560;
	if ((*info).res[1] > 1440)
		(*info).res[1] = 1440;
	if (ft_check_cameras_val((*info).cam) == -1)
		return (-1);
	if (ft_check_obj_val((*info).obj) == -1)
		return (-1);
	if (ft_check_lights_val((*info).l) == -1)
		return (-1);
	if ((*info).al.r < 0.00000000 || (*info).al.r > 1.00000000 ||
		ft_check_color_val((*info).al.color) == -1)
		return (-1);
	return (1);
}
