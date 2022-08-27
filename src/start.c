/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <lchristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:41:31 by lchristi          #+#    #+#             */
/*   Updated: 2022/08/25 15:41:34 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_intro(t_all *game)
{
	char	*path;

	path = "./xpm/logo_cub.xpm";
	game->intro = mlx_xpm_file_to_image(game->mlx, path, \
	&game->intro_w, &game->intro_h);
	mlx_put_image_to_window(game->mlx, game->win, \
	game->intro, (W_WIDTH / 2) - 150, (W_HEIGHT / 2) - 50);
	sleep(1);
	mlx_clear_window(game->mlx, game->win);
}

void	my_pixel_put(t_all *game, int x, int y, int color)
{
	char	*dest;

	dest = game->img.addr + (y * game->img.ll + x * (game->img.bpp / 8));
	*(unsigned int *)dest = color;
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

int	game_start(t_all *game) //
{
	draw_fc(game);
	draw_location(game);
    if (game->map_flag == 1)
	    draw_mmap(game);
	mlx_put_image_to_window(game->mlx, game->win, \
	game->img.img, 0, 0);
	return (1);
}
// check not f/c
// check duplicate
// check map close
