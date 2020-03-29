/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_lights_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:44:54 by ablanar           #+#    #+#             */
/*   Updated: 2019/12/30 17:48:13 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray.h"

int		ft_add_lights(t_l **light, t_vector coor, float b, t_vector color)
{
	t_l *new;
	t_l *buf;

	if (!(new = malloc(sizeof(t_l))))
		return (-1);
	new->coor = coor;
	new->b = b;
	new->color = color;
	new->next = NULL;
	buf = *light;
	if (*light)
	{
		while ((*light)->next)
			(*light) = (*light)->next;
		(*light)->next = new;
		*light = buf;
		return (1);
	}
	*light = new;
	return (1);
}

int		ft_add_l(t_info *info, char *line)
{
	t_vector	o;
	float		b;
	t_vector	color;
	int			i;

	i = 0;
	while (line[i] == ' ')
		i++;
	o = ft_parcor(&line[i]);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	b = ft_atof(&line[i]);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	color = ft_parcor(&line[i]);
	if (ft_add_lights(&info->l, o, b, color) == -1)
		return (-1);
	return (1);
}
