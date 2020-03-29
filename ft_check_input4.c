/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:22:44 by ablanar           #+#    #+#             */
/*   Updated: 2020/02/11 15:22:53 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray.h"

int		ft_check_a(char **line)
{
	int i;

	i = 0;
	if (ft_sizeof_tab(line) != 3)
		return (-1);
	if (ft_check_fl(line[1]) == -1)
		return (-1);
	if (ft_check_color(line[2]) == -1)
		return (-1);
	return (1);
}

int		ft_check_pos(char *line)
{
	char	**tab;
	int		k;

	k = 0;
	if (!(tab = ft_split(line, ',')))
		return (-1);
	while (tab[k] != NULL)
	{
		if (ft_check_fl(tab[k]) == -1)
		{
			ft_free_tab(tab);
			return (-1);
		}
		k++;
	}
	return (ft_free_tab(tab));
}

int		ft_check_norm(char *line)
{
	char	**tab;
	int		k;

	k = 0;
	if (!(tab = ft_split(line, ',')))
		return (-1);
	if (ft_sizeof_tab(tab) != 3)
	{
		ft_free_tab(tab);
		return (-1);
	}
	while (tab[k] != NULL)
	{
		if (ft_check_fl(tab[k]) == -1)
		{
			ft_free_tab(tab);
			return (-1);
		}
		k++;
	}
	return (ft_free_tab(tab));
}

int		ft_check_c(char **line)
{
	int i;

	i = 0;
	if (ft_sizeof_tab(line) != 4)
		return (-1);
	if (ft_check_pos(line[1]) == -1)
		return (-1);
	if (ft_check_norm(line[2]) == -1)
		return (-1);
	while (line[3][i])
	{
		if (!(line[3][i] <= '9' && line[3][i] >= '0'))
			return (-1);
		i++;
	}
	return (1);
}

int		ft_check_l(char **line)
{
	int i;

	i = 0;
	if (ft_check_pos(line[1]) == -1)
		return (-1);
	if (ft_check_fl(line[2]) == -1)
		return (-1);
	if (ft_check_color(line[3]) == -1)
		return (-1);
	return (1);
}
