/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pl_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 18:36:19 by ablanar           #+#    #+#             */
/*   Updated: 2019/12/30 17:58:55 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray_bonus.h"

int		ft_obs_pl(t_info info, t_pl *pl, t_vector l, t_vector d)
{
	double t0;

	while (pl)
	{
		t0 = -ft_dot_product(pl->norm, ft_vsbst(d,
		ft_vsbst(pl->coor, info.cam->o))) / ft_dot_product(pl->norm, l);
		if (t0 < 1 - 1e-4 && t0 > 1e-4)
			return (1);
		pl = pl->next;
	}
	return (0);
}
