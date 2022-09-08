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

void	key_hook_a(t_all *game)
{
	if (game->map.map[(int)(game->pl.pos.y)][(int)(game->pl.pos.x - \
	game->ray.plane.x * MS)] == '0' || game->map.map[(int)(game->pl.pos.y)] \
	[(int)(game->pl.pos.x - game->ray.plane.x * MS)] == '3')
		game->pl.pos.x -= game->ray.plane.x * MS;
	if (game->map.map[(int)(game->pl.pos.y - game->ray.plane.y * MS)] \
	[(int)(game->pl.pos.x)] == '0' || game->map.map[(int)(game->pl.pos.y - \
	game->ray.plane.y * MS)][(int)(game->pl.pos.x)] == '3')
		game->pl.pos.y -= game->ray.plane.y * MS;
}

void	key_hook_d(t_all *game)
{
	if (game->map.map[(int)(game->pl.pos.y)] \
		[(int)(game->pl.pos.x + game->ray.plane.x * MS)] == '0' ||
		game->map.map[(int)(game->pl.pos.y)] \
		[(int)(game->pl.pos.x + game->ray.plane.x * MS)] == '3')
		game->pl.pos.x += game->ray.plane.x * MS;
	if (game->map.map[(int)(game->pl.pos.y + game->ray.plane.y * MS)] \
		[(int)(game->pl.pos.x)] == '0' ||
		game->map.map[(int)(game->pl.pos.y + game->ray.plane.y * MS)] \
		[(int)(game->pl.pos.x)] == '3')
		game->pl.pos.y += game->ray.plane.y * MS;
}

void	key_hook_w(t_all *game)
{
	if (game->map.map[(int)(game->pl.pos.y)]
		[(int)(game->pl.pos.x + game->pl.dir.x * MS)] == '0' ||
		game->map.map[(int)(game->pl.pos.y)]
		[(int)(game->pl.pos.x + game->pl.dir.x * MS)] == '3')
		game->pl.pos.x += game->pl.dir.x * MS;
	if (game->map.map[(int)(game->pl.pos.y + game->pl.dir.y * MS)]
		[(int)(game->pl.pos.x)] == '0' ||
		game->map.map[(int)(game->pl.pos.y + game->pl.dir.y * MS)]
		[(int)(game->pl.pos.x)] == '3')
		game->pl.pos.y += game->pl.dir.y * MS;
}

void	key_hook_s(t_all *game)
{
	if (game->map.map[(int)(game->pl.pos.y)]
		[(int)(game->pl.pos.x - game->pl.dir.x * MS)] == '0' ||
		game->map.map[(int)(game->pl.pos.y)]
		[(int)(game->pl.pos.x - game->pl.dir.x * MS)] == '3')
		game->pl.pos.x -= game->pl.dir.x * MS;
	if (game->map.map[(int)(game->pl.pos.y - game->pl.dir.y * MS)]
		[(int)(game->pl.pos.x)] == '0' ||
		game->map.map[(int)(game->pl.pos.y - game->pl.dir.y * MS)]
		[(int)(game->pl.pos.x)] == '3')
		game->pl.pos.y -= game->pl.dir.y * MS;
}
