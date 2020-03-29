/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:49:48 by ablanar           #+#    #+#             */
/*   Updated: 2020/02/12 15:51:58 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray.h"

int		ft_check(char *s)
{
	char	*b;
	int		i;

	i = 0;
	b = ".rt";
	while (s[i])
		i++;
	i--;
	if (s[i] != b[2])
		return (0);
	i--;
	if (s[i] != b[1])
		return (0);
	i--;
	if (s[i] != b[0])
		return (0);
	return (1);
}

int		ft_check_obj_val(t_obj obj)
{
	if (ft_check_sp_val(obj.sp) == -1 || ft_check_pl_val(obj.pl) == -1 ||
		ft_check_sq_val(obj.sq) == -1 || ft_check_tr_val(obj.tr) == -1 ||
		ft_check_cy_val(obj.cy) == -1)
		return (-1);
	else
		return (1);
}

int		ft_check_lights_val(t_l *lights)
{
	while (lights != NULL)
	{
		if (lights->b < 0 || lights->b > 1.00000000)
			return (-1);
		if (ft_check_color_val(lights->color) == -1)
			return (-1);
		lights = lights->next;
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

int		ft_parse_rt(int fd, t_info *info)
{
	char	*line;

	while ((get_next_line(fd, &line)) > 0)
	{
		if (ft_check_input(line) == -1 || ft_reader(info, line) == -1)
		{
			free(line);
			close(fd);
			return (-1);
		}
		free(line);
	}
	free(line);
	close(fd);
	if (ft_check_objects_val(info) == -1)
		return (-1);
	return (1);
}
