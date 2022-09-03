//
// Created by thsiu on 26.08.22.
//

#include "cub3d.h"

void	key_hook_lr(int key, t_all *game)
{
    double	old_dir_x;
    double	old_plane_x;


    old_dir_x = game->pl.dir.x;
    old_plane_x = game->ray.plane.x;
    if (key == KEY_LEFT)
    {
        game->pl.dir.x = game->pl.dir.x * cos (-RS) - game->pl.dir.y *
                                                      sin (-RS);
        game->pl.dir.y = old_dir_x * sin(-RS) + game->pl.dir.y * cos(-RS);
        game->ray.plane.x = game->ray.plane.x * cos(-RS) -
                            game->ray.plane.y * sin (-RS);
        game->ray.plane.y = old_plane_x * sin(-RS) + game->ray.plane.y *
                                                     cos (-RS);
    }
    if (key == KEY_RIGHT)
    {
        game->pl.dir.x = game->pl.dir.x * cos(RS) - game->pl.dir.y * sin(RS);
        game->pl.dir.y = old_dir_x * sin(RS) + game->pl.dir.y * cos(RS);
        game->ray.plane.x = game->ray.plane.x * cos(RS) - \
		game->ray.plane.y * sin (RS);
        game->ray.plane.y = old_plane_x * sin(RS) + \
		game->ray.plane.y * cos (RS);
    }
}

int	mouse_hook(int x, int y, t_all *all)
{
    (void) y;

    mlx_mouse_hide(all->mlx, all->win);// если хочешь расскоменти, но мне кажется для наглядности лучше оставить курсор так
    //if (x < 0 || x > W_WIDTH)
    //mlx_mouse_move(all->mlx, all->win, W_WIDTH / 2, W_HEIGHT / 2); // Не понимаю зачем здесь это условие, мы не можем выйти за границы x из-за статичных размеров окна
    if (x > all->pl.mouse_x)
        key_hook_lr(KEY_RIGHT, all);
    else if (x < all->pl.mouse_x)
        key_hook_lr(KEY_LEFT, all);
    all->pl.mouse_x = x;
    return (0);
}