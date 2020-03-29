/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:49:48 by ablanar           #+#    #+#             */
/*   Updated: 2020/02/11 14:43:19 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray_bonus.h"

int		ft_check(char *s)
{
	char	*b;
	int		i;

	i = 0;
	b = ".rt";
	while (s[i])
		i++;
	i--;
	if (s[i] != b[2])
		return (0);
	i--;
	if (s[i] != b[1])
		return (0);
	i--;
	if (s[i] != b[0])
		return (0);
	return (1);
}

int		ft_reader_help(t_info *info, char *line)
{
	if (line[0] == 'y')
		return (ft_add_cy(info, &line[1]));
	if (line[0] == ' ')
		return (ft_add_c(info, &line[1]));
	if (line[0] == 'u')
		return (ft_add_cube(info, &line[1]));
	return (-1);
}

int		ft_reader(t_info *info, char *line)
{
	if (line[0] == '\0')
		return (1);
	if (line[0] == 'R')
		return (ft_add_r(info, &line[1]));
	if (line[0] == 'A')
		return (ft_add_a(info, &line[1]));
	if (line[0] == 'c')
		return (ft_reader_help(info, &line[1]));
	if (line[0] == 'l')
		return (ft_add_l(info, &line[1]));
	if (line[0] == 'p')
		return (ft_add_plane(info, &line[2]));
	if (line[0] == 't')
		return (ft_add_tr(info, &line[2]));
	if (line[0] == 's')
	{
		if (line[1] == 'p')
			return (ft_add_spheres(info, &line[2]));
		if (line[1] == 'q')
			return (ft_add_sq(info, &line[2]));
	}
	return (-1);
}

int		ft_parse_rt(int fd, t_info *info)
{
	char	*line;

	while ((get_next_line(fd, &line)) > 0)
	{
		if (ft_check_input(line) == -1 || ft_reader(info, line) == -1)
		{
			free(line);
			close(fd);
			return (-1);
		}
		free(line);
	}
	free(line);
	close(fd);
	if (ft_check_objects_val(info) == -1)
		return (-1);
	return (1);
}
