/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:41:11 by ablanar           #+#    #+#             */
/*   Updated: 2020/02/12 20:56:49 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray.h"

int		ft_check_color_val(t_vector color)
{
	if (color.x < 0 || color.x > 255 || color.y < 0 || color.y > 255 ||
		color.z < 0 || color.z > 255)
		return (-1);
	return (1);
}

int		ft_check_norm_val(t_vector norm)
{
	if (norm.x > 1.00000000 || norm.x < -1.00000000 || norm.y > 1.00000000 ||
		norm.y < -1.00000000 || norm.z > 1.00000000 || norm.z < -1.00000000)
		return (-1);
	else if (norm.x == 0 && norm.y == 0 && norm.z == 0)
		return (-1);
	return (1);
}

int		ft_check_cameras_val(t_cam *cam)
{
	if (cam == NULL)
		return (-1);
	while (cam != NULL)
	{
		if (ft_check_norm_val(cam->norm) == -1)
			return (-1);
		cam = cam->next;
	}
	return (1);
}
