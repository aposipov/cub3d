//
// Created by user on 25.08.22.
//
#include "cub3d.h"

void	check_position(t_all *game, int i, int j)
{
	if (i == 0 || j == 0)
		ft_error("Error: invalid map\n");
	if (!(game->map.map[i - 1][j]) || !(game->map.map[i][j - 1])
		|| !(game->map.map[i + 1][j]) || !(game->map.map[i][j + 1]))
		ft_error("Error: invalid map\n");
	if (game->map.map[i - 1][j] != '1' && game->map.map[i - 1][j] != '0')
		ft_error("Error: invalid map\n");
	if (game->map.map[i][j - 1] != '1' && game->map.map[i][j - 1] != '0')
		ft_error("Error: invalid map\n");
	if (game->map.map[i + 1][j] != '1' && game->map.map[i + 1][j] != '0')
		ft_error("Error: invalid map\n");
	if (game->map.map[i][j + 1] != '1' && game->map.map[i][j + 1] != '0')
		ft_error("Error: invalid map\n");
}

void	check_map_close(t_all *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == '0')
				check_position(game, i, j);
			j++;
		}
		i++;
	}
}