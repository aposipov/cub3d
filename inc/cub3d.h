
#ifndef CUB3D_CUB3D_H
# define CUB3D_CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx/mlx.h>
# include "get_next_line.h"
# include "cub3d_structs.h"
# include "cub3d_defines.h"

void	init_data(t_all *game);
void	init_mlx(t_all *game);
void	init_hooks(t_all *game);

int key_hook(int key);
int ft_close(void);

#endif
