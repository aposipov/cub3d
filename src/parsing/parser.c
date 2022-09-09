/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <lchristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:42:46 by lchristi          #+#    #+#             */
/*   Updated: 2022/08/25 15:42:49 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_pl(t_all *game)
{
	double	i;
	double	j;
	int		count;
	int		nswe;

	count = 0;
	i = -1;
	while (game->map.map[(int)++i])
	{
		j = -1;
		while (game->map.map[(int)i][(int)++j])
		{
			nswe = (int)game->map.map[(int)i][(int)j];
			if (nswe == 'N' || nswe == 'S' || nswe == 'W' || nswe == 'E')
			{
				count++;
				if (count == 2)
					ft_error("Error: find more one pl pos\n");
				set_pl_pos(game, nswe, i, j);
				game->map.map[(int)i][(int)j] = '0';
			}
		}
	}
	if (count == 0)
		ft_error("Error: find 0 pos\n");
}

void	pars_line(char *line, t_all *game)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '1' || line[i] == '0')
		pars_map(line, i, game);
	while (ft_isspace(*line))
		line++;
	if (*line == 'N' || *line == 'S' || \
		*line == 'W' || *line == 'E')
		pars_walls(line, game);
	if (line[0] == 'F' || line[0] == 'C')
		pars_fc(line, game);
}

void	pars_data(char *path, t_all *game)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		pars_line(line, game);
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
	}
	if (game->map.north == NULL || game->map.south == NULL
		|| game->map.west == NULL || game->map.east == NULL
		|| game->map.floor == -1 || game->map.ceiling == -1)
		ft_error("Error: NSWE/FC fail\n");
	else if (game->map.height == 0)
		ft_error("Error: empty map\n");
	check_pl(game);
	check_map_close(game);
	close(fd);
}
