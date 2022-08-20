//
// Created by user on 19.08.22.
//

#include "cub3d.h"

void	pixel_put(t_all *game, int x, int y, int color)
{
	char	*dest;

	dest = game->img.addr + (y * game->img.ll + x * (game->img.bpp / 8));
	*(unsigned int *)dest = color;
}

void	my_mlx_pixel_put(t_all *game, int x, int y, int color)
{
	int	i;
//	game->img.addr = malloc(sizeof(char) * 3);
//	if(!game->img.addr)
//		printf("addr failed\n");

	i = (x * game->img.bpp / 8) + (y * game->img.ll);
	game->img.addr[i] = (char)(color); // ss
	game->img.addr[i + 1] = (char)(color >> 8);
	game->img.addr[i + 2] = (char)(color >> 16);
}

void	draw_fc(t_all *game)
{
	int	x;
	int	y;
	game->map.ceiling = 16711680;
	game->map.floor = 16776960;

	x = -1;
	while (++x < W_WIDTH)
	{
		y = -1;
		while (++y < W_HEIGHT)
		{
			if (y < W_HEIGHT / 2)
				pixel_put(game, x, y, game->map.ceiling);
			else
				pixel_put(game, x, y, game->map.floor);
		}
	}
}

void	game_start(t_all *game)
{


	//malloc?
	draw_fc(game);
	//draw_raycasting(all);
	//draw_mini_map(all);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}