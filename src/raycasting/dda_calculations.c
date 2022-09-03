/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_calculations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsiu <lchristi@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:43:43 by lchristi          #+#    #+#             */
/*   Updated: 2022/08/25 15:43:49 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	side_dist(t_all *game)
{
	if (game->ray.ray_dir.x < 0)
	{
		game->ray.step_x = -1;
		game->ray.sd.x = (game->pl.pos.x - game->map.x) * game->ray.dd.x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.sd.x = (game->map.x + 1.0 - game->pl.pos.x) * game->ray.dd.x;
	}
	if (game->ray.ray_dir.y < 0)
	{
		game->ray.step_y = -1;
		game->ray.sd.y = (game->pl.pos.y - game->map.y) * game->ray.dd.y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.sd.y = (game->map.y + 1.0 - game->pl.pos.y) * game->ray.dd.y;
	}
}

void	dda_algo(t_all *game)
{
	while (game->ray.hit == 0)
	{
		if (game->ray.sd.x < game->ray.sd.y)
		{
			game->ray.sd.x += game->ray.dd.x;
			game->map.x += game->ray.step_x;
			game->ray.side = 0;
		}
		else
		{
			game->ray.sd.y += game->ray.dd.y;
			game->map.y += game->ray.step_y;
			game->ray.side = 1;
		}
		if (game->map.map[(int)(game->map.y)][(int)(game->map.x)] == '1' || \
            game->map.map[(int)(game->map.y)][(int)(game->map.x)] == '2' || \
            game->map.map[(int)(game->map.y)][(int)(game->map.x)] == '3')
			game->ray.hit = 1;
	}
}

void	calculations(t_all *game)
{
	if (game->ray.side == 0)
		game->ray.wall_dist = (game->ray.sd.x - game->ray.dd.x);
	else
		game->ray.wall_dist = (game->ray.sd.y - game->ray.dd.y);
	game->ray.height = (int)(W_HEIGHT / game->ray.wall_dist);
	game->ray.start = (-(game->ray.height) / 2 + W_HEIGHT / 2);
	if (game->ray.start < 0)
		game->ray.start = 0;
	game->ray.end = (game->ray.height / 2 + W_HEIGHT / 2);
	if (game->ray.end >= W_HEIGHT)
		game->ray.end = (W_HEIGHT - 1);
}

void	init_raycast(t_all *game, int x)
{
	game->ray.camera_x = ((2.0 * x / (double)(W_WIDTH)) - 1.0);
	game->ray.ray_dir.x = game->pl.dir.x + game->ray.plane.x * \
	game->ray.camera_x;
	game->ray.ray_dir.y = game->pl.dir.y + game->ray.plane.y * \
	game->ray.camera_x;
	game->map.x = (int)(game->pl.pos.x); //
	game->map.y = (int)(game->pl.pos.y); //
	game->ray.dd.x = fabs(1.0 / game->ray.ray_dir.x);
	game->ray.dd.y = fabs(1.0 / game->ray.ray_dir.y);
	game->ray.hit = 0;
	side_dist(game);
	dda_algo(game);
	calculations(game);
}
