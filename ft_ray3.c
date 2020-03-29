/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:16:38 by ablanar           #+#    #+#             */
/*   Updated: 2020/02/11 15:16:49 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray.h"

int		ft_check_sp_val(t_sp *sp)
{
	while (sp != NULL)
	{
		if (sp->r <= 0)
			return (-1);
		if (ft_check_color_val(sp->color) == -1)
			return (-1);
		sp = sp->next;
	}
	return (1);
}

int		ft_check_pl_val(t_pl *pl)
{
	while (pl != NULL)
	{
		if (ft_check_norm_val(pl->norm) == -1 ||
			ft_check_color_val(pl->color) == -1)
			return (-1);
		pl = pl->next;
	}
	return (1);
}

int		ft_check_sq_val(t_sq *sq)
{
	while (sq != NULL)
	{
		if (sq->size <= 0)
			return (-1);
		if (ft_check_norm_val(sq->norm) == -1 ||
			ft_check_color_val(sq->color) == -1)
			return (-1);
		sq = sq->next;
	}
	return (1);
}

int		ft_check_cy_val(t_cy *cy)
{
	while (cy != NULL)
	{
		if (cy->h <= 0 || cy->d <= 0)
			return (-1);
		if (ft_check_norm_val(cy->norm) == -1 ||
			ft_check_color_val(cy->color) == -1)
			return (-1);
		cy = cy->next;
	}
	return (1);
}

int		ft_check_tr_val(t_tr *tr)
{
	while (tr != NULL)
	{
		if (ft_check_color_val(tr->color) == -1)
			return (-1);
		tr = tr->next;
	}
	return (1);
}
