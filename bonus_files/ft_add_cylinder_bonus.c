/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_cylinder_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:44:49 by ablanar           #+#    #+#             */
/*   Updated: 2019/12/30 17:48:07 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray_bonus.h"

int		ft_add_newcy(t_cy **cy, t_vector *c, float *r)
{
	t_cy *new;
	t_cy *buf;

	if (!(new = malloc(sizeof(t_cy))))
		return (-1);
	new->coor = c[0];
	new->norm = c[1];
	new->color = c[2];
	new->d = r[0];
	new->h = r[1];
	new->next = NULL;
	buf = *cy;
	if (*cy)
	{
		while ((*cy)->next)
			*cy = (*cy)->next;
		(*cy)->next = new;
		(*cy) = buf;
		return (1);
	}
	(*cy) = new;
	return (1);
}

void	ft_add_cy_help(float *r, t_vector *c, char *line)
{
	int i;

	i = 0;
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	r[0] = ft_atof(&line[i]);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	r[1] = ft_atof(&line[i]);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	*c = ft_parcor(&line[i]);
}

int		ft_add_cy(t_info *info, char *line)
{
	int			i;
	t_vector	c[3];
	float		r[2];

	i = 0;
	while (line[i] == ' ')
		i++;
	c[0] = ft_parcor(&line[i]);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	c[1] = ft_parcor(&line[i]);
	ft_add_cy_help(&r[0], &c[2], &line[i]);
	if (ft_add_newcy(&info->obj.cy, c, r) == -1)
		return (-1);
	return (1);
}
