//
// Created by user on 21.08.22.
//

#include "cub3d.h"

char	*get_text_addr(char *line, t_all *game)
{
	int		i;
	int		bpp;
	int		ll;
	int endian;
	int w,h;
	void	*img;
	char	*adr;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '.' && line[i + 1] && line [i + 2] == '/')
	{
		img = mlx_xpm_file_to_image(game->mlx, line, &w, &h);
		i = i - 1 ;
		while (line[i++])
		{
			printf("%c", line[i]);
		}
		if (img == NULL || w != 64 || h != 64)
			printf("Error: wrong xpm file\n"); // do ft
		adr = mlx_get_data_addr(img, &bpp, &ll, &endian);
		return (adr);
	}
	printf("Error: wrong texture file\n");
	return (NULL);
}

void	pars_nswe(char *line, t_all *game)
{
	if (ft_strncmp(line, "NO ", 3) == 0 || game->map.north == NULL)
		game->map.north = get_text_addr(line + 3, game);
	else if (ft_strncmp(line, "SO ", 3) == 0 || game->map.south == NULL)
		game->map.south = get_text_addr(line + 3, game);
	else if (ft_strncmp(line, "NO ", 3) == 0 || game->map.west == NULL)
		game->map.west = get_text_addr(line + 3, game);
	else if (ft_strncmp(line, "NO ", 3) == 0 || game->map.east == NULL)
		game->map.east = get_text_addr(line + 3, game);
	else
	{
		printf("Error: texture not found!\n");
		exit(1);
	}
}

void	pars_line(char *line, t_all *game)
{
	int i;

	i = 0;
	if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W' || line[0] == 'E')
		pars_nswe(line, game);
	if (line[0] == 'F' || line[0] == 'C')
	//	pars_fc(line, game);
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '1' || line [i] == '0')
		//pars_map(line, game);
	printf("pars line\n");
}

void	pars_data(char *path, t_all * game)
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