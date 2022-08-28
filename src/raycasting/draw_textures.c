/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsiu <lchristi@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:43:57 by lchristi          #+#    #+#             */
/*   Updated: 2022/08/25 15:44:00 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pre_processing(t_all *game)
{
	double	wall_x;

	if (game->ray.side == 0)
		wall_x = game->pl.pos.y + game->ray.wall_dist * game->ray.ray_dir.y;
	else
		wall_x = game->pl.pos.x + game->ray.wall_dist * game->ray.ray_dir.x;
	wall_x -= floor(wall_x);
	game->wall.tex_x = (int)(wall_x * (double)(T_WIDTH));
	if (game->ray.side == 0 && game->ray.ray_dir.x > 0)
		game->wall.tex_x = T_WIDTH - game->wall.tex_x - 1;
	if (game->ray.side == 1 && game->ray.ray_dir.y < 0)
		game->wall.tex_x = T_WIDTH - game->wall.tex_x - 1;
	game->wall.step = 1.0 * T_WIDTH / game->ray.height;
	game->wall.tex_pos = (game->ray.start - W_HEIGHT / 2 + \
	game->ray.height / 2) * game->wall.step;
}

int	texturing(t_all *game, unsigned int *color)
{
	if (game->ray.side == 0 && game->map.map[(int)(game->map.y)][(int)(game->map.x)] != '2'
        && game->map.map[(int)(game->map.y)][(int)(game->map.x)] != '3')
	{
		if (game->ray.ray_dir.x >= 0)
			*color = ((unsigned int *)(game->map.east))
			[T_HEIGHT * game->wall.tex_y + game->wall.tex_x];
		else
			*color = ((unsigned int *)(game->map.west))
			[T_HEIGHT * game->wall.tex_y + game->wall.tex_x];
	}
	if (game->ray.side == 1 && game->map.map[(int)(game->map.y)][(int)(game->map.x)] != '2'
        && game->map.map[(int)(game->map.y)][(int)(game->map.x)] != '3')
    {
        if (game->ray.ray_dir.y >= 0)
            *color = ((unsigned int *) (game->map.south))
            [T_HEIGHT * game->wall.tex_y + game->wall.tex_x];
        else
            *color = ((unsigned int *) (game->map.north))
            [T_HEIGHT * game->wall.tex_y + game->wall.tex_x];
    }
    if (game->map.map[(int)(game->map.y)][(int)(game->map.x)] == '2')
    {
        *color = ((unsigned int *) (game->map.door))
        [T_HEIGHT * game->wall.tex_y + game->wall.tex_x];
    }
    if (game->map.map[(int)(game->map.y)][(int)(game->map.x)] == '3')
    {
        *color = ((unsigned int *) (game->map.o_door))
        [T_HEIGHT * game->wall.tex_y + game->wall.tex_x];
    }
        return (*color);
}



void	textures(t_all *game, int x)
{
	int				y;
	unsigned int	color;

	pre_processing(game);
	y = game->ray.start;
	while (y <= game->ray.end)
	{
		game->wall.tex_y = (int)game->wall.tex_pos & (T_HEIGHT - 1);
		game->wall.tex_pos += game->wall.step;
		color = texturing(game, &color);
		my_pixel_put(game, x, y, color);
		y++;
	}
}

void	draw_location(t_all *game)
{
	int	x;

	x = -1;
	while (++x < W_WIDTH)
	{
		init_raycast(game, x);
		textures(game, x);
	}
}
