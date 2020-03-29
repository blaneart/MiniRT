/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_square_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:07:58 by ablanar           #+#    #+#             */
/*   Updated: 2019/12/30 17:48:57 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray_bonus.h"

int		ft_add_square(t_sq **square, t_vector *c, float size)
{
	t_sq	*new;
	t_sq	*buf;

	if (!(new = malloc(sizeof(t_sq))))
		return (-1);
	new->coor = c[0];
	new->size = size;
	new->norm = c[1];
	new->color = c[2];
	new->next = NULL;
	buf = *square;
	if (*square)
	{
		while ((*square)->next)
			(*square) = (*square)->next;
		(*square)->next = new;
		*square = buf;
		return (1);
	}
	*square = new;
	return (1);
}

void	ft_add_sq_help(t_vector *c, float *size, char *line)
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

int		ft_add_sq(t_info *info, char *line)
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
	ft_add_sq_help(&c[2], &size, &line[i]);
	return (ft_add_square(&info->obj.sq, c, size));
}
