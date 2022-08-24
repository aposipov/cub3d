//
// Created by user on 24.08.22.
//

#include "cub3d.h"

void side_dist(t_all *data) // вычисление боковой дистанции
{
	if (data->ray.ray_dir.x < 0)
	{
		data->ray.step_x = -1;
		data->ray.sd.x = (data->pl.pos.x - data->map.x) * data->ray.dd.x;
	}
	else
	{
		data->ray.step_x = 1;
		data->ray.sd.x = (data->map.x + 1.0 - data->pl.pos.x) * data->ray.dd.x;
	}
	if (data->ray.ray_dir.y < 0)
	{
		data->ray.step_y = -1;
		data->ray.sd.y = (data->pl.pos.y - data->map.y) * data->ray.dd.y;
	}
	else
	{
		data->ray.step_y = 1;
		data->ray.sd.y = (data->map.y + 1.0 - data->pl.pos.y) * data->ray.dd.y;
	}
}

void    dda_algo(t_all *all) // алгоритм DDA-линий
{
	while (all->ray.hit == 0)
	{
		if (all->ray.sd.x < all->ray.sd.y)
		{
			all->ray.sd.x += all->ray.dd.x;
			all->map.x += all->ray.step_x;
			all->ray.side = 0;
		}
		else
		{
			all->ray.sd.y += all->ray.dd.y;
			all->map.y += all->ray.step_y;
			all->ray.side = 1;
		}
		if (all->map.map[(int)(all->map.y)][(int)(all->map.x)] == '1')
			all->ray.hit = 1;
	}
}

void	calculations(t_all *all) // абсолютно не понимаю  как мы к этому пришли, но все формулы с гайда на рейкастинг)))))
{
	if (all->ray.side == 0)
		all->ray.wall_dist = (all->ray.sd.x - all->ray.dd.x);
	else
		all->ray.wall_dist = (all->ray.sd.y - all->ray.dd.y);
	all->ray.height = (int)(W_HEIGHT / all->ray.wall_dist);
	all->ray.start = (-(all->ray.height) / 2 + W_HEIGHT / 2);
	if (all->ray.start < 0)
		all->ray.start = 0;
	all->ray.end = (all->ray.height / 2 + W_HEIGHT / 2);
	if (all->ray.end >= W_HEIGHT)
		all->ray.end = (W_HEIGHT - 1);
}

void init_raycast(t_all *data, int x) // функции вычисления лучей (https://lodev.org/cgtutor/raycasting.html)
{
	data->ray.camera_x = (2.0 * x / (double)(W_WIDTH - 1.0));
	data->ray.ray_dir.x = data->pl.dir.x + data->ray.plane.x * data->ray.camera_x; // вернул инцииализацию плоскостей в pars_nswe.c
	data->ray.ray_dir.y = data->pl.dir.y + data->ray.plane.y * data->ray.camera_x;
	data->map.x = (int)(data->pl.pos.x);
	data->map.y = (int)(data->pl.pos.y);
	data->ray.dd.x = fabs(1.0 / data->ray.ray_dir.x);
	data->ray.dd.y = fabs(1.0 / data->ray.ray_dir.y);
	data->ray.hit = 0;
	side_dist(data);
	dda_algo(data);
	calculations(data);
}