/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_spheres_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:45:18 by ablanar           #+#    #+#             */
/*   Updated: 2020/02/12 22:00:21 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray_bonus.h"

int		ft_add_sp(t_sp **sp, t_vector coor, float r, t_vector color)
{
	t_sp *buf;
	t_sp *new;

	buf = (*sp);
	if (!(new = malloc(sizeof(t_sp))))
		return (-1);
	new->coor = coor;
	new->r = r;
	new->color = color;
	new->next = NULL;
	if (*sp)
	{
		while ((*sp)->next)
			(*sp) = (*sp)->next;
		(*sp)->next = new;
		*sp = buf;
		return (1);
	}
	*sp = new;
	return (1);
}

int		ft_add_spheres(t_info *info, char *line)
{
	int			i;
	t_vector	coor;
	float		r;
	t_vector	color;

	i = 0;
	while (line[i] == ' ')
		i++;
	coor = ft_parcor(&line[i]);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	r = ft_atof(&line[i]) / 2;
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	color = ft_parcor(&line[i]);
	return ((ft_add_sp(&info->obj.sp, coor, r, color)));
}
