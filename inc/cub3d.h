/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <lchristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:37:50 by lchristi          #+#    #+#             */
/*   Updated: 2022/08/25 15:38:00 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

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
void	init_mlx(t_all *game);
void	init_hooks(t_all *game);
/*parsing*/
void	pars_data(char *path, t_all *game);
void	pars_walls(char *line, t_all *game);
void	pars_fc(char *line, t_all *game);
void	pars_map(char *line, int i, t_all *game);
void	set_pl_pos(t_all *all, int nswe, double i, double j);
/**/
int		game_start(t_all *game);
/*raycast*/
void	draw_location(t_all *game);
void	init_raycast(t_all *game, int x);

/*hooks*/
int		key_hook(int key, t_all *game);
int     mouse_hook(int x, int y, t_all *all);
int		exit_hook(t_all *game);
void	key_hook_lr(int key, t_all *game);
void	key_hook_w(t_all *game);
void	key_hook_a(t_all *game);
void	key_hook_s(t_all *game);
void	key_hook_d(t_all *game);

/*util*/
void	ft_error(char *str);
char	*del_n(char *line);
void	my_pixel_put(t_all *game, int x, int y, int color);
void	draw_intro(t_all *game);
void	draw_mmap(t_all *game);
void	draw_pixel(t_all *all, int i, int j, int color);
void	free_tmp(char **arr);

void	check_map_close(t_all *game);

#endif
