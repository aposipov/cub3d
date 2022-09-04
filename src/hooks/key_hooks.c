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
    if (game->map.map[(int)(game->pl.pos.y)] \
    [(int)(game->pl.pos.x - game->ray.plane.x * MS)] == '0' ||
        game->map.map[(int)(game->pl.pos.y)] \
    [(int)(game->pl.pos.x - game->ray.plane.x * MS)] == '4')
        game->pl.pos.x -= game->ray.plane.x * MS;
    if (game->map.map[(int)(game->pl.pos.y - game->ray.plane.y * MS)] \
    [(int)(game->pl.pos.x)] == '0' ||
        game->map.map[(int)(game->pl.pos.y - game->ray.plane.y * MS)] \
    [(int)(game->pl.pos.x)] == '4')
        game->pl.pos.y -= game->ray.plane.y * MS;
}

void    key_hook_d(t_all *game)
{
    if (game->map.map[(int)(game->pl.pos.y)] \
		[(int)(game->pl.pos.x + game->ray.plane.x * MS)] == '0' ||
        game->map.map[(int)(game->pl.pos.y)] \
		[(int)(game->pl.pos.x + game->ray.plane.x * MS)] == '4')
        game->pl.pos.x += game->ray.plane.x * MS;
    if (game->map.map[(int)(game->pl.pos.y + game->ray.plane.y * MS)] \
		[(int)(game->pl.pos.x)] == '0' ||
        game->map.map[(int)(game->pl.pos.y + game->ray.plane.y * MS)] \
		[(int)(game->pl.pos.x)] == '4')
        game->pl.pos.y += game->ray.plane.y * MS;
}

void	key_hook_w(t_all *game)
{
    if (game->map.map[(int)(game->pl.pos.y)]
        [(int)(game->pl.pos.x + game->pl.dir.x * MS)] == '0' ||
        game->map.map[(int)(game->pl.pos.y)]
        [(int)(game->pl.pos.x + game->pl.dir.x * MS)] == '4')
        game->pl.pos.x += game->pl.dir.x * MS;
    if (game->map.map[(int)(game->pl.pos.y + game->pl.dir.y * MS)]
        [(int)(game->pl.pos.x)]  == '0' ||
        game->map.map[(int)(game->pl.pos.y + game->pl.dir.y * MS)]
        [(int)(game->pl.pos.x)]  == '4')
        game->pl.pos.y += game->pl.dir.y * MS;
}

void key_hook_s(t_all *game)
{
    if (game->map.map[(int)(game->pl.pos.y)]
        [(int)(game->pl.pos.x - game->pl.dir.x * MS)] == '0' ||
        game->map.map[(int)(game->pl.pos.y)]
        [(int)(game->pl.pos.x - game->pl.dir.x * MS)] == '4')
        game->pl.pos.x -= game->pl.dir.x * MS;
    if (game->map.map[(int)(game->pl.pos.y - game->pl.dir.y * MS)]
        [(int)(game->pl.pos.x)] == '0' ||
        game->map.map[(int)(game->pl.pos.y - game->pl.dir.y * MS)]
        [(int)(game->pl.pos.x)] == '4')
        game->pl.pos.y -= game->pl.dir.y * MS;
}

void	open_the_doors(t_all *game)
{
    if (game->map.map[(int)(game->pl.pos.y)][(int)(game->pl.pos.x + 1)] == '2')
        game->map.map[(int)(game->pl.pos.y)][(int)(game->pl.pos.x + 1)] = '4';
    else if (game->map.map[(int)(game->pl.pos.y)][(int)(game->pl.pos.x - 1)] == '2')
        game->map.map[(int)(game->pl.pos.y)][(int)(game->pl.pos.x - 1)] = '4';
    else if (game->map.map[(int)(game->pl.pos.y + 1)][(int)(game->pl.pos.x)] == '2')
        game->map.map[(int)(game->pl.pos.y + 1)][(int)(game->pl.pos.x)] = '4';
    else if (game->map.map[(int)(game->pl.pos.y - 1)][(int)(game->pl.pos.x)] == '2')
        game->map.map[(int)(game->pl.pos.y - 1)][(int)(game->pl.pos.x)] = '4';
    else if (game->map.map[(int)(game->pl.pos.y)][(int)(game->pl.pos.x + 1)]
	== '4')
        game->map.map[(int)(game->pl.pos.y)][(int)(game->pl.pos.x + 1)] = '2';
    else if (game->map.map[(int)(game->pl.pos.y)][(int)(game->pl.pos.x - 1)]
	== '4')
        game->map.map[(int)(game->pl.pos.y)][(int)(game->pl.pos.x - 1)] = '2';
    else if (game->map.map[(int)(game->pl.pos.y + 1)][(int)(game->pl.pos.x)]
	== '4')
        game->map.map[(int)(game->pl.pos.y + 1)][(int)(game->pl.pos.x)] = '2';
    else if (game->map.map[(int)(game->pl.pos.y - 1)][(int)(game->pl.pos.x)]
	== '4')
        game->map.map[(int)(game->pl.pos.y - 1)][(int)(game->pl.pos.x)] = '2';
}

int	exit_hook(t_all *game) // free?
{
	printf(GREEN"Exit!\n"NC);
	//(void)game;
    mlx_destroy_image(game->mlx, game->img.img);
    mlx_destroy_window(game->mlx, game->win);
    //free_tmp(game->tmp);
//    if (game->map.north)
//	{
//		printf("north = %p\n", game->map.north);
//		free(game->map.north);
//	}
//	else
//		printf("no!!!!\n");
	//    free(game->map.south);
    free(game->map.west);
//    free(game->map.east);
//    free(game->map.door);
//    free(game->map.o_door);
//    free(game);
	exit(0);
}

int	key_hook(int key, t_all *game)
{
	if (key == KEY_ESC)
        exit_hook(game);
	else if (key == KEY_M)
    {
        if (game->map_flag == 0)
            game->map_flag = 1;
        else
            game->map_flag = 0;
    }
	else if (key == KEY_W)
        key_hook_w(game);
    else if (key == KEY_S)
        key_hook_s(game);
	else if (key == KEY_A)
        key_hook_a(game);
    else if (key == KEY_D)
        key_hook_d(game);
	else if (key == KEY_LEFT || key == KEY_RIGHT)
		key_hook_lr(key, game);
    else if (key == KEY_SPACE)
    {
        open_the_doors(game);
    }
	return (0);
}


