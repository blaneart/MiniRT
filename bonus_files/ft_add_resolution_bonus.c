/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_resolution_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:45:10 by ablanar           #+#    #+#             */
/*   Updated: 2020/02/12 18:44:09 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray_bonus.h"

int	ft_add_r(t_info *info, char *line)
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
	info->res[0] = ft_atoi(&line[i]);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	info->res[1] = ft_atoi(&line[i]);
	flag = 1;
	return (1);
}
