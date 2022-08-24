//
// Created by thsiu on 24.08.22.
//
#include "cub3d.h"

void	pre_processing(t_all *all)
{
    double	wall_x;

    if (all->ray.side == 0)
        wall_x = all->pl.pos.y + all->ray.wall_dist * all->ray.ray_dir.y;
    else
        wall_x = all->pl.pos.x + all->ray.wall_dist * all->ray.ray_dir.x;
    wall_x -= floor(wall_x); // ЭТА ФУНКЦИЯ Я НЕ ПОНИМАЮ ЧТО С НЕЙ, пришлось из-за нее в мейк отдельный флаг добавлять, я когда завтра текстуры делать буду наверное напишу альтернативу
    all->wall.tex_x = (int)(wall_x * (double)(64));
    if (all->ray.side == 0 && all->ray.ray_dir.x > 0)
        all->wall.tex_x = 64 - all->wall.tex_x - 1;
    if (all->ray.side == 1 && all->ray.ray_dir.y < 0)
        all->wall.tex_x = 64 - all->wall.tex_x - 1;
    all->wall.step = 1.0 * 64 / all->ray.height;
    all->wall.tex_pos = (all->ray.start - W_HEIGHT / 2 + all->ray.height / 2)
                        * all->wall.step;
}

int	texturing(t_all *all, unsigned int *color)
{
    if (all->ray.side == 0)
    {
        if (all->ray.ray_dir.x >= 0)
            *color = ((unsigned int *)(all->map.east))
            [64 * all->wall.tex_y + all->wall.tex_x];
        else
            *color = ((unsigned int *)(all->map.west))
            [64 * all->wall.tex_y + all->wall.tex_x];
    }
    else if (all->ray.side == 1)
    {
        if (all->ray.ray_dir.y >= 0)
            *color = ((unsigned int *)(all->map.south))
            [64 * all->wall.tex_y + all->wall.tex_x];
        else
            *color = ((unsigned int *)(all->map.north))
            [64 * all->wall.tex_y + all->wall.tex_x];
    }
    return (*color);
}

void	textures(t_all *all, int x) // этот кусок кода и выше абсолютно не мои, они здесь для проверки вычислений
{
    int				y;
    unsigned int	color;

    pre_processing(all);
    y = all->ray.start;
    while (y <= all->ray.end)
    {
        all->wall.tex_y = (int)all->wall.tex_pos & (64 - 1);
        all->wall.tex_pos += all->wall.step;
        color = texturing(all, &color);
        my_pixel_put(all, x, y, color);
        y++;
    }
}

void draw_location(t_all *data)
{
    int x;

    x = -1;
    while (++x < W_WIDTH)
    {
        init_raycast(data, x);
        textures(data, x);
    }
}
