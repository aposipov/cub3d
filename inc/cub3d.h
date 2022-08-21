
#ifndef CUB3D_CUB3D_H
# define CUB3D_CUB3D_H

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
void	pars_fc(char *line, t_all *game);
void	pars_map(char *line, int i, t_all *game);
/**/
void	game_start(t_all *game);
/*util*/
int		key_hook(int key);
int		ft_close(void);
void	ft_error(char *str);


void	draw_intro(t_all *game);
#endif
