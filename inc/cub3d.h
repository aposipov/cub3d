
#ifndef CUB3D_CUB3D_H
# define CUB3D_CUB3D_H

#include <X11/X.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx/mlx.h>
# include "libft.h"
# include "my_colours.h"
# include "get_next_line.h"
# include "cub3d_structs.h"
# include "cub3d_defines.h"

/*init*/
void	init_data(t_all *game);
void	init_test(t_all *game);
void	init_mlx(t_all *game);
void	init_hooks(t_all *game);
/*parsing*/
void	pars_data(char *path, t_all * game);
void	pars_nswe(char *line, t_all *game);
void	pars_fc(char *line, t_all *game);
void	pars_map(char *line, int i, t_all *game);
void	set_pl_pos(t_all *all, int nswe, double i, double j);

/**/
int		game_start(t_all *game);

/*raycast*/
void    draw_location(t_all *game);
void    init_raycast(t_all *game, int x);

/*util*/
int		key_hook(int key, t_all *game);
int		exit_hook(void);
void	ft_error(char *str);
char	*del_n(char *line);

void	my_pixel_put(t_all *game, int x, int y, int color);
void	my_mlx_pixel_put(t_all *game, int x, int y, int color);
void	draw_intro(t_all *game);
void	draw_mmap(t_all *game);
void	draw_pixel(t_all *all, int i, int j, int color);


#endif
