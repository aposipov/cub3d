//
// Created by user on 21.08.22.
//

#include "cub3d.h"

void	pars_fc(char *line, t_all *game)
{
	if (ft_strncmp(line, "F ", 2) == 0 || game->map.floor == -1)
		printf("F\n");
	else if (ft_strncmp(line, "C ", 2) == 0 || game->map.ceiling == -1)
		printf("C\n");
	else
	{
		printf("Error: F and C not found!\n");
		exit(1);
	}
}