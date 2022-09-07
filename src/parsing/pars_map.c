/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <lchristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:43:08 by lchristi          #+#    #+#             */
/*   Updated: 2022/08/25 15:43:10 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tmp(char **arr)
{
	char **tmp;
	tmp = arr;

	while (*arr)
		free(*arr++);
	free(tmp);
	tmp = NULL;
}

int	check_line(char *line, int i)
{
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != '2' && line[i] != '3' &&\
        line[i] != 'N' && line[i] != 'S' && line[i] != 'W' && line[i] != 'E' &&\
        !ft_isspace(line[i]))
			return (0);
		i++;
	}
	return (1);
}

void	pars_map(char *line, int i, t_all *game)
{
	//char	**tmp;
	int		h;

	h = -1;
	game->map.height++;
	game->tmp = (char **)malloc(sizeof(char *) * (game->map.height + 1));
	if (!game->tmp)
		ft_error("Error: malloc fail\n");
	game->tmp[game->map.height] = NULL;
	while (++h < (game->map.height - 1))
		game->tmp[h] = ft_strdup(game->map.map[h]);
	line = del_n(line);
	if (check_line(line, i))
		game->tmp[h] = ft_strdup(line);
	else
	{
		game->tmp[h] = NULL;
		free(game->tmp); // exit
		ft_error("Error: invalid map\n");
	}
	if (game->map.height > 1)
		free_tmp(game->map.map);
	game->map.map = game->tmp;
	printf("map = %s\n", game->map.map[h]); //
	free(line); // del n
}
// check position
// check map close
