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

void	key_hook_ad(int key, t_all *game)
{
	if (key == KEY_A)
	{
		if (game->map.map[(int)(game->pl.pos.y)] \
		[(int)(game->pl.pos.x - game->ray.plane.x * MS)] == '0')
			game->pl.pos.x -= game->ray.plane.x * MS;
		if (game->map.map[(int)(game->pl.pos.y - game->ray.plane.y * MS)] \
		[(int)(game->pl.pos.x)] == '0')
			game->pl.pos.y -= game->ray.plane.y * MS;
	}
	if (key == KEY_D)
	{
		if (game->map.map[(int)(game->pl.pos.y)] \
		[(int)(game->pl.pos.x + game->ray.plane.x * MS)] == '0')
			game->pl.pos.x += game->ray.plane.x * MS;
		if (game->map.map[(int)(game->pl.pos.y + game->ray.plane.y * MS)] \
		[(int)(game->pl.pos.x)] == '0')
			game->pl.pos.y += game->ray.plane.y * MS;
	}
}

void	key_hook_ws(int key, t_all *game)
{
	if (key == KEY_W)
	{
		if (game->map.map[(int)(game->pl.pos.y)]
			[(int)(game->pl.pos.x + game->pl.dir.x * MS)] == '0')
			game->pl.pos.x += game->pl.dir.x * MS;
		if (game->map.map[(int)(game->pl.pos.y + game->pl.dir.y * MS)]
			[(int)(game->pl.pos.x)] == '0')
			game->pl.pos.y += game->pl.dir.y * MS;
	}
	if (key == KEY_S)
	{
		if (game->map.map[(int)(game->pl.pos.y)]
			[(int)(game->pl.pos.x - game->pl.dir.x * MS)] == '0')
			game->pl.pos.x -= game->pl.dir.x * MS;
		if (game->map.map[(int)(game->pl.pos.y - game->pl.dir.y * MS)]
			[(int)(game->pl.pos.x)] == '0')
			game->pl.pos.y -= game->pl.dir.y * MS;
	}
}

int	exit_hook(void) // free?
{
	printf(GREEN"Exit!\n"NC);
	exit(0);
}

int	key_hook(int key, t_all *game)
{
	if (key == KEY_ESC)
		exit_hook();
	else if (key == KEY_M)
    {
        if (game->map_flag == 0)
            game->map_flag = 1;
        else
            game->map_flag = 0;
    }
	else if (key == KEY_W || key == KEY_S)
		key_hook_ws(key, game);
	else if (key == KEY_A || key == KEY_D)
		key_hook_ad(key, game);
	else if (key == KEY_LEFT || key == KEY_RIGHT)
		key_hook_lr(key, game);
//	printf("key = %d\n", key); // del
	return (0);
}


