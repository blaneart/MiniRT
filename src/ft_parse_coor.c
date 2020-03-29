/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_coor_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:49:43 by ablanar           #+#    #+#             */
/*   Updated: 2019/12/30 17:52:43 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ray.h"

t_vector	ft_parcor(char *s)
{
	t_vector	new;
	int			i;
	int			num;

	i = 0;
	num = 0;
	while (s[i] == ' ')
		i++;
	new.x = ft_atof(&s[i]);
	while ((s[i] >= '0' && s[i] <= '9') || s[i] == '.' || s[i] == '-')
		i++;
	i++;
	new.y = ft_atof(&s[i]);
	while ((s[i] >= '0' && s[i] <= '9') || s[i] == '.' || s[i] == '-')
		i++;
	i++;
	new.z = ft_atof(&s[i]);
	return (new);
}
