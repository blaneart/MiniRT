/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:44:42 by ablanar           #+#    #+#             */
/*   Updated: 2020/02/12 20:13:23 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray.h"

int		ft_add_camera(t_cam **cam, t_vector o, t_vector norm, float fov)
{
	t_cam *new;
	t_cam *buf;

	if (!(new = malloc(sizeof(t_cam))))
		return (-1);
	new->norm = norm;
	new->o = o;
	new->fov = fov;
	new->next = NULL;
	buf = (*cam);
	if (*cam)
	{
		while ((*cam)->next)
			(*cam) = (*cam)->next;
		new->prev = *cam;
		(*cam)->next = new;
		(*cam) = buf;
		return (1);
	}
	*cam = new;
	(*cam)->prev = NULL;
	return (1);
}

int		ft_add_c(t_info *info, char *line)
{
	int				i;
	t_vector		o;
	t_vector		norm;
	float			fov;

	i = 0;
	while (line[i] == ' ')
		i++;
	o = ft_parcor(&line[i]);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	norm = ft_parcor(&line[i]);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	fov = ft_atof(&line[i]);
	if (fov > 180 || fov < 0)
		return (-1);
	if (ft_add_camera(&info->cam, o, norm, fov) == -1)
		return (-1);
	return (1);
}
