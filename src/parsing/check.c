/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_fc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <lchristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:42:57 by lchristi          #+#    #+#             */
/*   Updated: 2022/08/25 15:42:59 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_position(t_all *game, int i, int j)
{
	if (i == 0 || j == 0)
		ft_error("Error: invalid map\n");
	if (!(game->map.map[i - 1][j]) || !(game->map.map[i][j - 1])
		|| !(game->map.map[i + 1][j]) || !(game->map.map[i][j + 1]))
		ft_error("Error: invalid map\n");
	if (game->map.map[i - 1][j] != '1' && game->map.map[i - 1][j] != '0' &&
		game->map.map[i - 1][j] != '2' && game->map.map[i - 1][j] != '3')
		ft_error("Error: invalid map\n");
	if (game->map.map[i][j - 1] != '1' && game->map.map[i][j - 1] != '0' &&
		game->map.map[i][j - 1] != '2' && game->map.map[i][j - 1] != '3')
		ft_error("Error: invalid map\n");
	if (game->map.map[i + 1][j] != '1' && game->map.map[i + 1][j] != '0' &&
		game->map.map[i + 1][j] != '2' && game->map.map[i + 1][j] != '3')
		ft_error("Error: invalid map\n");
	if (game->map.map[i][j + 1] != '1' && game->map.map[i][j + 1] != '0' &&
		game->map.map[i][j + 1] != '2' && game->map.map[i][j + 1] != '3')
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
