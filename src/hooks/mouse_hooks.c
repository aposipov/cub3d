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

void	key_hook_l(t_all *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->pl.dir.x;
	old_plane_x = game->ray.plane.x;
	game->pl.dir.x = game->pl.dir.x * cos (-RS) - \
			game->pl.dir.y * sin(-RS);
	game->pl.dir.y = old_dir_x * sin(-RS) + \
			game->pl.dir.y * cos(-RS);
	game->ray.plane.x = game->ray.plane.x * cos(-RS) - \
			game->ray.plane.y * sin(-RS);
	game->ray.plane.y = old_plane_x * sin(-RS) + \
			game->ray.plane.y * cos(-RS);
}

void	key_hook_r(t_all *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->pl.dir.x;
	old_plane_x = game->ray.plane.x;
	game->pl.dir.x = game->pl.dir.x * cos(RS) - \
			game->pl.dir.y * sin(RS);
	game->pl.dir.y = old_dir_x * sin(RS) + \
			game->pl.dir.y * cos(RS);
	game->ray.plane.x = game->ray.plane.x * cos(RS) - \
			game->ray.plane.y * sin(RS);
	game->ray.plane.y = old_plane_x * sin(RS) + \
			game->ray.plane.y * cos(RS);
}

int	mouse_hook(int x, int y, t_all *all)
{
	(void) y;
	if (x > all->pl.mouse_x)
		key_hook_r(all);
	else if (x < all->pl.mouse_x)
		key_hook_l(all);
	all->pl.mouse_x = x;
	return (0);
}
