/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_ambient_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:52:02 by ablanar           #+#    #+#             */
/*   Updated: 2020/02/12 18:30:07 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray.h"

int	ft_add_a(t_info *info, char *line)
{
	int			i;
	static int	flag = 0;

	i = 0;
	if (flag == 1)
		return (-1);
	if (line[i] != ' ')
		return (-1);
	while (line[i] == ' ')
		i++;
	info->al.r = ft_atof(&line[i]);
	if (info->al.r > 1 || info->al.r < 0)
		return (-1);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	info->al.color = ft_parcor(&line[i]);
	flag = 1;
	return (1);
}
