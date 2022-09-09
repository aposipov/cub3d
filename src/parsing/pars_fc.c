/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_fc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <lchristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:42:57 by lchristi          #+#    #+#             */
/*   Updated: 2022/08/25 15:42:59 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	torgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	rgb(char *line)
{
	int		i;
	char	**colors;
	int		rgb;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	colors = ft_split(line, ',');
	if (!colors)
		ft_error("Error: malloc fail\n");
	rgb = torgb(ft_atoi(colors[0]), \
	ft_atoi(colors[1]), ft_atoi(colors[2]));
	free_tmp(colors);
	return (rgb);
}

void	check_comma(const char *line)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (line[i])
	{
		if (line[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		ft_error("Error: wrong color\n");
}

void	pars_fc(char *line, t_all *game)
{
	if ((ft_strncmp(line, "F ", 2) == 0) && game->map.floor == -1)
	{
		check_comma(line);
		game->map.floor = rgb(line);
	}
	else if ((ft_strncmp(line, "C ", 2) == 0) && game->map.ceiling == -1)
	{
		check_comma(line);
		game->map.ceiling = rgb(line);
	}
	else
		ft_error("Error: color F/C not found or F/C more than one\n");
}
