/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_plane_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:45:04 by ablanar           #+#    #+#             */
/*   Updated: 2019/12/30 17:48:20 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray.h"

int		ft_add_newpl(t_pl **pl, t_vector *c)
{
	t_pl *new;
	t_pl *buf;

	if (!(new = malloc(sizeof(t_pl))))
		return (-1);
	new->coor = c[0];
	new->norm = c[1];
	new->color = c[2];
	new->next = NULL;
	buf = *pl;
	if (*pl)
	{
		while ((*pl)->next)
			(*pl) = (*pl)->next;
		(*pl)->next = new;
		*pl = buf;
		return (1);
	}
	*pl = new;
	return (1);
}

int		ft_add_plane(t_info *info, char *line)
{
	int			i;
	t_vector	c[3];

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
	if ((ft_add_newpl(&info->obj.pl, c)) == -1)
		return (-1);
	return (1);
}
