//
// Created by thsiu on 30.08.22.
//

#include "cub3d.h"


void	draw_sprite(t_all *game)
{
    int	pos[2];
    int	color;

    pos[x] = (int)game->sprite.init[x];
    while (pos[X] < game->sprite.end[X])
    {
        pos[Y] = (int)game->sprite.init[Y];
        while (pos[Y] < game->sprite.end[Y])
        {
//            if (is_inside_screen(cub->settings.screen, pos[X], pos[Y]))
//            {
                if (game->sprite.distance < game->ray[pos[X]].dist)
                {
                    color = get_sprite_color(sprite, &sprite->texture, pos,
                                             &cub->settings);
                    if (color != 0x000000)
                        put_pixel(&cub->img, pos[X], pos[Y], color);
                }
//            }
            pos[Y]++;
        }
        pos[X]++;
    }
}



void	put_sprite(t_all *game)
{
//    int	i;

//    i = 0;
//    while (i < cub->game.num_sprites)
//    {
//        set_sprite_values(cub, &sprites[i], player);
        if (game->sprite.angle > PI)
            game->sprite.angle -= TWO_PI;
        if (game->sprite.angle < -PI)
            game->sprite.angle += TWO_PI;
        game->sprite.angle = fabs(game->sprite.angle);
        if (game->sprite.angle < (HALF_FOV + 0.2)) && game->sprite.active)
            sprites[i].visible = TRUE;
        else
            sprites[i].visible = FALSE;
//        i++;
//    }
    //sort_sprites(sprites, cub);
//    i = 0;
//    while (i < cub->game.num_sprites)
//    {
//        if (sprites[i].visible)
            draw_sprite(cub, &sprites[i], ray);
//        i++;
//    }
}