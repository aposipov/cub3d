//
// Created by user on 21.08.22.
//


#include "cub3d.h"

void pars_line(char *line, t_all *game)
{
	int i;

	i = 0;
	if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W' || line[0] == 'E')
	//	pars_nswe(line, game);
	if (line[0] == 'F' || line[0] == 'C')
	//	pars_fc(line, game);
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '1' || line [i] == '0')
		//pars_map(line, game);
		;
}

void pars_data(char *path, t_all * game)
{
	int fd;
	char *line;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	while (line != NULL)
	{
		pars_line(line, game);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s\n", line);
	}
	free(line);
	close(fd);
}