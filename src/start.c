//
// Created by user on 19.08.22.
//

#include "cub3d.h"

void	draw_intro(t_all *game)
{
	char *path = "../xpm/logo_cub.xpm"; // for make ./

	game->intro = mlx_xpm_file_to_image(game->mlx, path, &game->intro_w,
										&game->intro_h);
	mlx_put_image_to_window(game->mlx, game->win, game->intro, (W_WIDTH / 2)
	- 150,(W_HEIGHT / 2) - 50);
	sleep(3);
	mlx_clear_window(game->mlx, game->win);
}

void	my_pixel_put(t_all *game, int x, int y, int color)
{
	char	*dest;

	dest = game->img.addr + (y * game->img.ll + x * (game->img.bpp / 8));
	*(unsigned int *)dest = color;
}

void	my_mlx_pixel_put(t_all *game, int x, int y, int color)
{
	//not work ? ss why
	int	i;

	i = (x * game->img.bpp / 8) + (y * game->img.ll);
	game->img.addr[i] = (char)(color); // ss
	game->img.addr[i + 1] = (char)(color >> 8);
	game->img.addr[i + 2] = (char)(color >> 16);
}

void	draw_fc(t_all *game)
{
	int	x;
	int	y;

	x = -1;
	while (++x < W_WIDTH)
	{
		y = -1;
		while (++y < W_HEIGHT)
		{
			if (y < W_HEIGHT / 2)
				my_pixel_put(game, x, y, game->map.ceiling);
			else
				my_pixel_put(game, x, y, game->map.floor);
		}
	}
}

void	game_start(t_all *game)
{
	draw_intro(game);
	draw_fc(game);
	//draw_raycasting(all); // 2
	draw_mmap(game); // 3
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}