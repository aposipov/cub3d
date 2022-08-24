//
// Created by user on 19.08.22.
//

#include "cub3d.h"

//void	init_test(t_all *game)
//{
//	game->map.ceiling = 99999999; // pars
//	game->map.floor = 88888888; // pars
//	game->map.north = NULL;
//	game->map.south = NULL;
//	game->map.west = NULL;
//	game->map.east = NULL;
//	printf("*** init data test ver ***\n");
//}

void	init_data(t_all *game)
{
	// null data
	game->mlx = NULL;
	game->img.img = NULL;
	game->img.addr = NULL;
	game->map.map = NULL;
	game->map.ceiling = -1;
	game->map.floor = -1;
	game->map.north = NULL;
	game->map.south = NULL;
	game->map.west = NULL;
	game->map.east = NULL;
	game->map.height = 0;
	game->pl.pos.x = 0;
	game->pl.pos.y = 0;
	game->pl.dir.x = 0;
	game->pl.dir.y = 0;
	game->ray.plane.x = 0;
	game->ray.plane.y = 0;

	printf("*** init data ***\n");
}

void init_mlx(t_all *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, W_WIDTH, W_HEIGHT, "cub3d");
	game->img.img = mlx_new_image(game->mlx, W_WIDTH, W_HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp,
									   &game->img.ll, &game->img.endian);
}

void	init_hooks(t_all *game)
{
	mlx_key_hook(game->win, key_hook, game);
//	mlx_hook(game->win, 2, 0, key_hook, game); // faster?
	mlx_mouse_hook(game->win, key_hook, game); // ? move l r
	mlx_mouse_show(game->mlx, game->win); // for what
	mlx_mouse_move(game->mlx, game->win, 300,300); // for what
	mlx_hook(game->win, 17, 0, exit_hook, 0); // ? &game
}