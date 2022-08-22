//
// Created by user on 21.08.22.
//

#include "cub3d.h"

char *del_n(char *line)
{
	int i = 0;
	char *tmp;
	int len;

	len = ft_strlen(line);
	if (line[len] != '\n')
		line[len + 1] = '\n';
	tmp = malloc (sizeof(char) * len);
	if (!tmp)
		ft_error(RED"del_n malloc"NC);
	while (line[i] != '\n')
	{
		tmp[i] = line[i];
		i++;
	}
//	*tmp2 = &tmp;
//	free(tmp);
	return (tmp);
}

char	*get_text_addr(char *line)
{
	int		i;
	char *tmp;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '.' && line[i + 1] == '.' && line [i + 2] == '/')
	{
//			printf("%s\n", line); //
			tmp = del_n(line);
			printf("tmp = %s\n", tmp);
			return (tmp);
	}
	ft_error(RED"Error: wrong texture file\n"NC);
	return (0);
}

void	pars_nswe(char *line, t_all *game)
{
	if (ft_strncmp(line, "NO ", 3) == 0 && game->map.north == NULL)
	{
		game->map.north = get_text_addr(line + 3);
		//printf("map.north = %s\n", game->map.north);
	}
	else if (ft_strncmp(line, "SO ", 3) == 0 && game->map.south == NULL)
		game->map.south = get_text_addr(line + 3);
	else if (ft_strncmp(line, "WE ", 3) == 0 && game->map.west == NULL)
		game->map.west = get_text_addr(line + 3);
	else if (ft_strncmp(line, "EA ", 3) == 0 && game->map.east == NULL)
		game->map.east = get_text_addr(line + 3);
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
	free(line);
	//printf("data ok\n"); //
	close(fd);
}