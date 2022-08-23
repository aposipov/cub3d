//
// Created by user on 22.08.22.
//

#include "cub3d.h"

void	draw_pixel(t_all *all, int i, int j, int color)
{
	int	y;
	int	x;

	y = W_HEIGHT * 0.01 * i;
	while (y < W_HEIGHT * 0.01 * (i + 1))
	{
		x = W_HEIGHT * 0.01 * j;
		while (x < W_HEIGHT * 0.01 * (j + 1))
		{
			my_pixel_put(all, x + 15, y + 15, color);
			x++;
		}
		y++;
	}
}

void	draw_mmap(t_all *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == '1')
				draw_pixel(game, i, j, 0xEEEEEE);
			else
			{
				j++;
				continue ;
			}
			j++;
		}
		i++;
	}
	draw_pixel(game, game->pl.pos.y, game->pl.pos.x, 0x27CE06);
}