/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <lchristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:39:12 by lchristi          #+#    #+#             */
/*   Updated: 2022/08/25 15:39:16 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCTS_H
# define CUB3D_STRUCTS_H

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}	t_data;

typedef struct s_map
{
	char	**map;
	int		height;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
    char    *door;
    char    *o_door;
	int		floor;
	int		ceiling;
	int		x;
	int		y;
}			t_map;

typedef struct s_point
{
	double	x;
	double	y;
}			t_point;

typedef struct s_pl
{
	t_point	pos;
	t_point	dir;
    int     mouse_x;
}			t_pl;

typedef struct s_ray
{
	double	camera_x;
	t_point	ray_dir;
	t_point	plane;
	t_point	dd;
	t_point	sd;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	wall_dist;
	int		height;
	int		start;
	int		end;
}			t_ray;

typedef struct s_wall
{
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	double	step;
}			t_wall;

typedef struct s_sprite
{
    int     x;
    int     y;
    float   angle;

}   t_sprite;

typedef struct s_all
{
	void	    *mlx;
	void	    *win;
	void	    *intro;
	int		    intro_w;
	int		    intro_h;
    int         map_flag;
	t_data	    img;
	t_map	    map;
	t_pl	    pl;
	t_ray	    ray;
	t_wall	    wall;
    t_sprite    sprite;
}	t_all;

#endif
