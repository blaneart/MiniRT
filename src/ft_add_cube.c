/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_cube_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 15:10:03 by ablanar           #+#    #+#             */
/*   Updated: 2020/02/11 14:19:55 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ray.h"

int		ft_add_cu(t_cu **cu, t_vector c[3], float size)
{
	t_cu	*new;
	t_cu	*buf;

	if (!(new = malloc(sizeof(t_cu))))
		return (-1);
	new->coor = c[0];
	new->size = size;
	new->norm = c[1];
	new->color = c[2];
	new->next = NULL;
	buf = *cu;
	if (*cu != NULL)
	{
		while ((*cu)->next)
			(*cu) = (*cu)->next;
		(*cu)->next = new;
		*cu = buf;
		return (1);
	}
	*cu = new;
	return (1);
}

void	ft_add_cu_help(t_vector *c, float *size, char *line)
{
	int i;

	i = 0;
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	*size = ft_atof(&line[i]);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	*c = ft_parcor(&line[i]);
}

int		ft_add_cube(t_info *info, char *line)
{
	int			i;
	t_vector	c[3];
	float		size;

	i = 0;
	while (line[i] == ' ')
		i++;
	c[0] = ft_parcor(&line[i]);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	c[1] = ft_parcor(&line[i]);
	ft_add_cu_help(&c[2], &size, &line[i]);
	if (ft_add_cu(&info->obj.cu, c, size) == -1)
		return (-1);
	return (1);
}
