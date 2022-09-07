/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <lchristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:40:07 by lchristi          #+#    #+#             */
/*   Updated: 2022/08/25 15:40:11 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	open_the_doors(t_all *game)
{
	if (game->map.map[(int)(game->pl.pos.y)][(int)(game->pl.pos.x + 1)] == '2')
		game->map.map[(int)(game->pl.pos.y)][(int)(game->pl.pos.x + 1)] = '3';
	else if (game->map.map[(int)(game->pl.pos.y)][(int)(game->pl.pos.x - 1)]
	== '2')
		game->map.map[(int)(game->pl.pos.y)][(int)(game->pl.pos.x - 1)] = '3';
	else if (game->map.map[(int)(game->pl.pos.y + 1)][(int)(game->pl.pos.x)]
	== '2')
		game->map.map[(int)(game->pl.pos.y + 1)][(int)(game->pl.pos.x)] = '3';
	else if (game->map.map[(int)(game->pl.pos.y - 1)][(int)(game->pl.pos.x)]
	== '2')
		game->map.map[(int)(game->pl.pos.y - 1)][(int)(game->pl.pos.x)] = '3';
	else if (game->map.map[(int)(game->pl.pos.y)][(int)(game->pl.pos.x + 1)]
	== '3')
		game->map.map[(int)(game->pl.pos.y)][(int)(game->pl.pos.x + 1)] = '2';
	else if (game->map.map[(int)(game->pl.pos.y)][(int)(game->pl.pos.x - 1)]
	== '3')
		game->map.map[(int)(game->pl.pos.y)][(int)(game->pl.pos.x - 1)] = '2';
	else if (game->map.map[(int)(game->pl.pos.y + 1)][(int)(game->pl.pos.x)]
	== '3')
		game->map.map[(int)(game->pl.pos.y + 1)][(int)(game->pl.pos.x)] = '2';
	else if (game->map.map[(int)(game->pl.pos.y - 1)][(int)(game->pl.pos.x)]
	== '3')
		game->map.map[(int)(game->pl.pos.y - 1)][(int)(game->pl.pos.x)] = '2';
}

int	exit_hook(t_all *game)
{
	printf(GREEN"Exit!\n"NC);
	free_tmp(game->tmp);
	mlx_destroy_image(game->mlx, game->intro);
	mlx_destroy_image(game->mlx, game->img.img);
	mlx_destroy_image(game->mlx, game->img.img_t[0]);
	mlx_destroy_image(game->mlx, game->img.img_t[1]);
	mlx_destroy_image(game->mlx, game->img.img_t[2]);
	mlx_destroy_image(game->mlx, game->img.img_t[3]);
	mlx_destroy_image(game->mlx, game->img.img_t[4]);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

int	key_hook(int key, t_all *game)
{
	if (key == KEY_ESC)
		exit_hook(game);
	else if (key == KEY_W)
		key_hook_w(game);
	else if (key == KEY_S)
		key_hook_s(game);
	else if (key == KEY_A)
		key_hook_a(game);
	else if (key == KEY_D)
		key_hook_d(game);
	else if (key == KEY_LEFT)
		key_hook_l(game);
	else if (key == KEY_RIGHT)
		key_hook_r(game);
	else if (key == KEY_SPACE)
		open_the_doors(game);
	else if (key == KEY_M)
	{
		if (game->map_flag == 0)
			game->map_flag = 1;
		else
			game->map_flag = 0;
	}
	return (0);
}
