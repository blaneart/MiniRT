/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:16:09 by ablanar           #+#    #+#             */
/*   Updated: 2020/02/12 20:54:47 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray.h"

int		ft_reader_help(t_info *info, char *line)
{
	if (line[0] == 'y')
		return (ft_add_cy(info, &line[1]));
	if (line[0] == ' ')
		return (ft_add_c(info, &line[1]));
	return (-1);
}

int		ft_reader(t_info *info, char *line)
{
	if (line[0] == '\0')
		return (1);
	if (line[0] == 'R')
		return (ft_add_r(info, &line[1]));
	if (line[0] == 'A')
		return (ft_add_a(info, &line[1]));
	if (line[0] == 'c')
		return (ft_reader_help(info, &line[1]));
	if (line[0] == 'l')
		return (ft_add_l(info, &line[1]));
	if (line[0] == 'p')
		return (ft_add_plane(info, &line[2]));
	if (line[0] == 't')
		return (ft_add_tr(info, &line[2]));
	if (line[0] == 's')
	{
		if (line[1] == 'p')
			return (ft_add_spheres(info, &line[2]));
		if (line[1] == 'q')
			return (ft_add_sq(info, &line[2]));
	}
	return (-1);
}

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
