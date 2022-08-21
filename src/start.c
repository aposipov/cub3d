//
// Created by user on 19.08.22.
//

#include "cub3d.h"

//void	draw_pixel(t_all *all, int i, int j, int color)
//{
//	int	y;
//	int	x;
//
//	y = HEIGHT * 0.01 * i;
//	while (y < HEIGHT * 0.01 * (i + 1))
//	{
//		x = HEIGHT * 0.01 * j;
//		while (x < HEIGHT * 0.01 * (j + 1))
//		{
//			pixel_put(all, x + 5, y + 5, color);
//			x++;
//		}
//		y++;
//	}
//}

//void	draw_mini_map(t_all *all)
//{
//	int	i;
//	int	j;
//
//	i = 0;
//	while (all->map.map[i])
//	{
//		j = 0;
//		while (all->map.map[i][j])
//		{
//			if (all->map.map[i][j] == '1')
//				draw_pixel(all, i, j, 0xEEEEEE);
//			else
//			{
//				j++;
//				continue ;
//			}
//			j++;
//		}
//		i++;
//	}
//	draw_pixel(all, all->plr.pos.y, all->plr.pos.x, 0x27CE06);
//}

void	draw_intro(t_all *game)
{
	char *path = "../xpm/logo_cub.xpm"; // make ./

	game->intro = mlx_xpm_file_to_image(game->mlx, path, &game->intro_w,
										&game->intro_h);
	mlx_put_image_to_window(game->mlx, game->win, game->intro, 500, 200);
	sleep(3);
	mlx_clear_window(game->mlx, game->win);
}

void	pixel_put(t_all *game, int x, int y, int color)
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
				my_mlx_pixel_put(game, x, y, game->map.ceiling);
			else
				my_mlx_pixel_put(game, x, y, game->map.floor);
		}
	}
}

void	game_start(t_all *game)
{
	draw_intro(game);
	draw_fc(game);
	//draw_mini_map(all); // 3
	//draw_raycasting(all); // 2
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}