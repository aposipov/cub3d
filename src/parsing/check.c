//
// Created by user on 25.08.22.
//
#include "cub3d.h"

void	check_position(t_all *game, int i, int j)
{
	if (i == 0 || j == 0)
		ft_error("Error: invalid map 9\n");
	if (!(game->map.map[i - 1][j]) || !(game->map.map[i][j - 1])
		|| !(game->map.map[i + 1][j]) || !(game->map.map[i][j + 1]))
		ft_error("Error: invalid map 6\n");
	if (game->map.map[i - 1][j] != '1' && game->map.map[i - 1][j] != '0' && game->map.map[i - 1][j] != '2' && game->map.map[i - 1][j] != '3')
		ft_error("Error: invalid map 3\n");
	if (game->map.map[i][j - 1] != '1' && game->map.map[i][j - 1] != '0' && game->map.map[i][j - 1] != '2' && game->map.map[i][j - 1] != '3')
		ft_error("Error: invalid map 1\n");
	if (game->map.map[i + 1][j] != '1' && game->map.map[i + 1][j] != '0' && game->map.map[i + 1][j] != '2' && game->map.map[i + 1][j] != '3')
		ft_error("Error: invalid map 2 \n");
	if (game->map.map[i][j + 1] != '1' && game->map.map[i][j + 1] != '0' && game->map.map[i][j + 1] != '2' && game->map.map[i][j + 1] != '3')
		ft_error("Error: invalid map 11\n");
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