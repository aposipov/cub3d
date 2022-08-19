//
// Created by user on 19.08.22.
//

#include <cub3d.h>

void	init_data(t_all *game)
{
	// null data
	game->map.ceiling = -1;
	game->map.floor = -1;
	printf("*** init data ***\n");
}

void init_mlx(t_all *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, W_WIDTH, W_HEIGHT, "cub3d");
}

void	init_hooks(t_all *game)
{
	mlx_key_hook(game->win, key_hook, &game);
	mlx_mouse_hook(game->win, key_hook, &game); // ? move l r
	mlx_hook(game->win, 17, 0, ft_close, 0); // ? &game
}