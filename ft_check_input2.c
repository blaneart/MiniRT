/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:21:39 by ablanar           #+#    #+#             */
/*   Updated: 2020/02/11 15:21:53 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray.h"

int		ft_sizeof_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

int		ft_strlensp(char *line, char c)
{
	int i;

	i = 0;
	while (line[i] != c && line[i])
		i++;
	return (i);
}

int		ft_add_str(char **tab, char *line, int k, char c)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (!(tab[k] = malloc(sizeof(char) * ft_strlensp(line, c) + 1)))
		return (-1);
	while (line[i] != c && line[i])
	{
		tab[k][i] = line[i];
		i++;
	}
	tab[k][i] = '\0';
	return (1);
}

int		ft_str_count(char *line, char c)
{
	int i;
	int k;

	k = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == c || line[i] == c)
		{
			while ((line[i] == c || line[i] == c) && line[i])
				i++;
		}
		if (line[i])
			k++;
		while (line[i] != c && line[i] != c && line[i])
			i++;
	}
	return (k);
}

char	**ft_split(char *line, char c)
{
	char	**tab;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!(tab = malloc(sizeof(char *) * ft_str_count(line, c) + 1)))
		return (NULL);
	while (line[i])
	{
		while ((line[i] == c) && line[i])
			i++;
		if (line[i])
		{
			ft_add_str(tab, &line[i], k, c);
			k++;
		}
		while ((line[i] != c) && line[i])
			i++;
		if (line[i])
			i++;
	}
	tab[k] = NULL;
	return (tab);
}
