/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_triangle_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:45:58 by ablanar           #+#    #+#             */
/*   Updated: 2019/12/30 17:49:20 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ray.h"

int		ft_add_newtr(t_tr **tr, t_vector *c)
{
	t_tr *new;
	t_tr *buf;

	if (!(new = malloc(sizeof(t_tr))))
		return (-1);
	new->c[0] = c[0];
	new->c[1] = c[1];
	new->c[2] = c[2];
	new->color = c[3];
	new->next = NULL;
	buf = *tr;
	if (*tr)
	{
		while ((*tr)->next)
			*tr = (*tr)->next;
		(*tr)->next = new;
		*tr = buf;
		return (1);
	}
	*tr = new;
	return (1);
}

int		ft_add_tr(t_info *info, char *line)
{
	int			i;
	t_vector	c[4];

	i = 0;
	while (line[i] == ' ')
		i++;
	c[0] = ft_parcor(&line[i]);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	c[1] = ft_parcor(&line[i]);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	c[2] = ft_parcor(&line[i]);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	c[3] = ft_parcor(&line[i]);
	return (ft_add_newtr(&info->obj.tr, c));
}
