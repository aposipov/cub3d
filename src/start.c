//
// Created by user on 19.08.22.
//

#include "cub3d.h"

void	my_mlx_pixel_put(t_all *game, int x, int y, int color)
{
	int	i;

	i = (x * game->img.bpp / 8) + (y * game->img.ll);
	game->img.addr[i] = (char)(color);
	game->img.addr[i + 1] = (char)(color >> 8);
	game->img.addr[i + 2] = (char)(color >> 16);
}

void	draw_fc(t_all *game)
{
	int	x;
	int	y;
	game->map.ceiling = 16711680;
	game->map.floor = 16776960;

	game->img.addr = malloc(sizeof(char) * 3);
	if(!game->img.addr)
		printf("addr failed\n");

	x = -1;
	while (++x < W_WIDTH)
	{
		y = -1;
		while (++y < W_HEIGHT)
		{
			if (y < W_HEIGHT / 2)
				my_mlx_pixel_put(game, x, y, game->map.ceiling);
			else
				my_mlx_pixel_put(game, x, y, game->map.floor);
		}
	}
}

void	game_start(t_all *game)
{
	draw_fc(game);
	//draw_raycasting(all);
	//draw_mini_map(all);
	//mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->mlx.img, 0, 0);
}