//
// Created by user on 15.08.22.
//

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
}			t_pl;

typedef struct s_all
{
	void	*mlx;
	void	*win;
	void	*intro;
	int		intro_w;
	int 	intro_h;
	t_data	img;
	t_map	map;
	t_pl	pl;
}	t_all;

#endif
