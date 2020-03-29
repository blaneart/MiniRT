/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cam_mov_bonus2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:33:03 by ablanar           #+#    #+#             */
/*   Updated: 2020/02/11 17:33:16 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray_bonus.h"

void	ft_change_cam(t_cam **cam, int pos)
{
	if (pos == 2)
		(*cam)->o.x = (*cam)->o.x + 1;
	if (pos == 0)
		(*cam)->o.x = (*cam)->o.x - 1;
	if (pos == 1)
		(*cam)->o.z = (*cam)->o.z - 1;
	if (pos == 13)
		(*cam)->o.z = (*cam)->o.z + 1;
	if (pos == 12)
		(*cam)->o.y = (*cam)->o.y - 1;
	if (pos == 14)
		(*cam)->o.y = (*cam)->o.y + 1;
}
