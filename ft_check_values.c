/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_values_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:34:17 by ablanar           #+#    #+#             */
/*   Updated: 2020/02/11 14:34:32 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray.h"

int		ft_check_res(char **line)
{
	int i;

	i = 0;
	if (ft_sizeof_tab(line) != 3)
		return (-1);
	while (line[1][i])
	{
		if (!(line[1][i] <= '9' && line[1][i] >= '0'))
			return (-1);
		i++;
	}
	i = 0;
	while (line[2][i])
	{
		if (!(line[2][i] <= '9' && line[2][i] >= '0'))
			return (-1);
		i++;
	}
	return (1);
}

int		ft_check_int(char *line)
{
	int i;

	i = 0;
	if (line[i] == '-')
		i++;
	while (line[i])
	{
		if (!(line[i] <= '9' && line[i] >= '0'))
			return (-1);
		i++;
	}
	return (1);
}

int		ft_check_fl(char *line)
{
	int i;

	i = 0;
	if (line[i] == '-')
		i++;
	while (line[i])
	{
		if (line[i] == '.')
		{
			i++;
			while (line[i])
			{
				if (!(line[i] <= '9' && line[i] >= '0') && line[i] != '\0')
					return (-1);
				i++;
			}
			return (1);
		}
		if (!(line[i] <= '9' && line[i] >= '0'))
			return (-1);
		i++;
	}
	if (line[i])
		return (-1);
	return (1);
}

int		ft_free_tab(char **tab)
{
	int k;

	k = 0;
	if (tab == NULL)
		return (1);
	while (tab[k] != NULL)
	{
		free(tab[k]);
		k++;
	}
	free(tab);
	return (1);
}

int		ft_check_color(char *line)
{
	char	**tab;
	int		k;

	k = 0;
	tab = ft_split(line, ',');
	if (ft_sizeof_tab(tab) != 3)
	{
		ft_free_tab(tab);
		return (-1);
	}
	while (tab[k] != NULL)
	{
		if (ft_check_int(tab[k]) == -1)
		{
			ft_free_tab(tab);
			return (-1);
		}
		k++;
	}
	return (ft_free_tab(tab));
}
