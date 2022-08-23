//
// Created by user on 21.08.22.
//

#include "cub3d.h"

void find_nswe(t_all *game)
{
	double i;
	double j;
	int count;
	int nswe;

	count = 0;
	i = -1;
	while (game->map.map[(int)++i])
	{
		j = -1;
		while (game->map.map[(int)i][(int)++j])
		{
			nswe = game->map.map[(int)i][(int)j];
			if (nswe == 'N' || nswe == 'S' || nswe == 'W' || nswe == 'E')
			{
				count++;
				if (count == 2)
					ft_error(RED"Error: find more one pl pos\n"NC);
				set_pl_pos(game, nswe, i, j);
				game->map.map[(int)i][(int)j] = '0';
			}
		}
	}
	if (count == 0)
		ft_error(RED"Error: find 0 pos\n"NC);
}

void	pars_line(char *line, t_all *game)
{
	int i;

	i = 0;
	if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W' || line[0] == 'E')
		pars_nswe(line, game);
	else if (game->map.north == NULL || game->map.south == NULL || game->map
	.west	== NULL || game->map.east == NULL) // ??
		ft_error(RED"Error: texture not found!\n"NC);
	if (line[0] == 'F' || line[0] == 'C')
		pars_fc(line, game);
//	else if (game->map.floor == -1 || game->map.ceiling == -1)
//		ft_error(RED"Error: color F/C not found\n"NC);
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '1') //|| line [i] == '0'
		pars_map(line, i, game);

}

void	pars_data(char *path, t_all * game)
{
	int fd;
	char *line;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	//printf("%s\n", line); //
	while (line != NULL)
	{
		pars_line(line, game);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		//printf("%s\n", line); //
	}
	if (game->map.north == NULL || game->map.south == NULL
		|| game->map.west == NULL || game->map.east == NULL
		|| game->map.floor == -1 || game->map.ceiling == -1)
		ft_error(RED"Error: NSWE/FC fail"NC);
	find_nswe(game);
	//free(line);
	//printf("data ok\n"); //
	close(fd);
}