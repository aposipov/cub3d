//
// Created by user on 21.08.22.
//

#include "cub3d.h"

// check position
// check map close

int	check_line(char *line, int i)
{
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'W' && line[i] != 'E'
			&& !ft_isspace(line[i]))
			return (0);
		i++;
	}
	return (1);
}

void	pars_map(char *line, int i, t_all *game)
{
	char	**tmp;
	int		h;

	h = -1;
	game->map.height++;
	tmp = (char **)malloc(sizeof(char *) * (game->map.height + 1));
	if (!tmp)
	{
		printf("Error: malloc fail\n");
		exit(1);
	}
	tmp[game->map.height] = NULL;
	while (++h < (game->map.height - 1))
		tmp[h] = ft_strdup(game->map.map[h]);
	line = del_n(line);
	if (check_line(line, i))
		tmp[h] = ft_strdup(line);
	else
	{
		tmp[h] = NULL;
		free(tmp);
		ft_error(RED"Error: invalid map\n"NC);
	}
	if (game->map.height > 1)
		free(game->map.map);
	game->map.map = tmp;
	printf("map = %s\n", game->map.map[h]);
}