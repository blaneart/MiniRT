/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 16:33:52 by ablanar           #+#    #+#             */
/*   Updated: 2020/02/11 14:37:27 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ray.h"

int		ft_check_plane(char **line)
{
	if (ft_sizeof_tab(line) != 4)
		return (-1);
	if (ft_check_pos(line[1]) == -1)
		return (-1);
	if (ft_check_norm(line[2]) == -1)
		return (-1);
	if (ft_check_color(line[3]) == -1)
		return (-1);
	return (1);
}

int		ft_check_sq(char **line)
{
	if (ft_sizeof_tab(line) != 5)
		return (-1);
	if (ft_check_pos(line[1]) == -1)
		return (-1);
	if (ft_check_norm(line[2]) == -1)
		return (-1);
	if (ft_check_fl(line[3]) == -1)
		return (-1);
	if (ft_check_color(line[4]) == -1)
		return (-1);
	return (1);
}

int		ft_check_cy(char **line)
{
	if (ft_sizeof_tab(line) != 6)
		return (-1);
	if (ft_check_pos(line[1]) == -1)
		return (-1);
	if (ft_check_norm(line[2]) == -1)
		return (-1);
	if (ft_check_fl(line[3]) == -1)
		return (-1);
	if (ft_check_fl(line[4]) == -1)
		return (-1);
	if (ft_check_color(line[5]) == -1)
		return (-1);
	return (1);
}

int		ft_check_tr(char **line)
{
	if (ft_sizeof_tab(line) != 5)
		return (-1);
	if (ft_check_pos(line[1]) == -1)
		return (-1);
	if (ft_check_pos(line[2]) == -1)
		return (-1);
	if (ft_check_pos(line[3]) == -1)
		return (-1);
	if (ft_check_color(line[4]) == -1)
		return (-1);
	return (1);
}

int		ft_check_cu(char **line)
{
	if (ft_sizeof_tab(line) != 5)
		return (-1);
	if (ft_check_pos(line[1]) == -1)
		return (-1);
	if (ft_check_norm(line[2]) == -1)
		return (-1);
	if (ft_check_fl(line[3]) == -1)
		return (-1);
	if (ft_check_color(line[4]) == -1)
		return (-1);
	return (1);
}
