/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:45:10 by ablanar           #+#    #+#             */
/*   Updated: 2020/02/12 18:29:52 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray.h"

int	ft_add_r(t_info *info, char *line)
{
	int			i;
	static int	flag = 0;

	if (flag == 1)
		return (-1);
	i = 0;
	if (line[i] != ' ')
		return (-1);
	while (line[i] == ' ')
		i++;
	info->res[0] = ft_atoi(&line[i]);
	while (line[i] <= '9' && line[i] >= '0')
		i++;
	while (line[i] == ' ')
		i++;
	info->res[1] = ft_atoi(&line[i]);
	flag = 1;
	return (1);
}
