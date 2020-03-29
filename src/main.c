/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:51:18 by ablanar           #+#    #+#             */
/*   Updated: 2020/02/12 18:28:32 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ray.h"

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_null_info(t_info *info)
{
	info->cam = NULL;
	info->res[0] = 0;
	info->filter = 0;
	info->obj.sp = NULL;
	info->obj.pl = NULL;
	info->obj.sq = NULL;
	info->obj.tr = NULL;
	info->obj.cy = NULL;
	info->obj.cu = NULL;
	info->al.r = 0;
	ft_fill_v(&info->al.color, 0, 0, 0);
}

int		ft_open_file(char *file)
{
	int		errno;
	int		fd;
	char	*er;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		er = strerror(errno);
		write(2, er, ft_strlen(er));
		write(2, "\n", 1);
		exit(-1);
	}
	return (fd);
}

int		ft_error(void)
{
	write(2, "Error\nMistake in the scene file\n", 32);
	return (-1);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_info	info;

	if (argc == 2 || argc == 3)
	{
		if (ft_check(argv[1]))
		{
			if ((fd = ft_open_file(argv[1])) < 0)
				return (-1);
			ft_null_info(&info);
			if (ft_parse_rt(fd, &info) == -1)
				return (ft_error());
			if (argc == 3 && ft_strcmp(argv[2], "--save"))
				ft_save(info);
			else if (ft_check_inp(info) == -1)
				return (-1);
			else
				ft_draw(info);
		}
		else
			write(2, "Error\nWrong name of the file\n", 29);
	}
	else
		write(2, "Error\nWrong number of arguments\n", 32);
	return (0);
}
