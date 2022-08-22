//
// Created by user on 21.08.22.
//

#include "cub3d.h"

int	torgb(int r, int g, int b)
{
	return (1 << 24 | r << 16 | g << 8 | b);
}

int	rgb(char *line)
{
	int		i;
	char	**colors;
	int		rgb;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	colors = ft_split(line, ',');
	if (!colors)
		ft_error(RED"Error: malloc fail\n"NC);
	rgb = torgb(ft_atoi(colors[0]),
				ft_atoi(colors[1]),
				ft_atoi(colors[2]));
	free(colors);
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
		ft_error(RED"Error: wrong color\n"NC);
}

void	pars_fc(char *line, t_all *game)
{
	if ((ft_strncmp(line, "F ", 2) == 0) && game->map.floor == -1)
	{
		check_comma(line);
		game->map.floor = rgb(line);
		printf("fl = %d\n", game->map.floor);
	}
	else if ((ft_strncmp(line, "C ", 2) == 0) && game->map.ceiling == -1)
	{
		check_comma(line);
		game->map.ceiling = rgb(line);
		printf("cl = %d\n", game->map.ceiling);
	}
	else
		ft_error(RED"Error: color F/C not found\n"NC);
}
