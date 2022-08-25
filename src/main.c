/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <lchristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:40:36 by lchristi          #+#    #+#             */
/*   Updated: 2022/08/25 15:40:39 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(char *str)
{
	printf(RED"%s\n"NC, str);
	exit(EXIT_FAILURE);
}

static void	open_path(char const *path)
{
	int	fd;

	fd = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error("Error: file not exist\n");
	close(fd);
}

static void	check_path(char const *path)
{
	int	i;

	i = 0;
	while (path[i])
		i++;
	if (!(path[i - 1] == 'b' && path[i - 2] == 'u' && path[i - 3] == 'c' && \
	path[i - 4] == '.' && path[i -5] >= 48))
	{
		printf(RED"Error: check you path! -> %s\n"NC, path);
		exit(1);
	}
	open_path(path);
}

int	main(int argc, char **argv)
{
	t_all	game;

	if (argc == 2)
	{
		check_path(argv[1]);
		init_data(&game);
		init_mlx(&game);
		init_hooks(&game);
		pars_data(argv[1], &game);
		draw_intro(&game);
		mlx_loop_hook(game.mlx, game_start, &game);
		mlx_loop(game.mlx);
	}
	else
	{
		printf(RED"Error: should be argument the path to map!\n"NC);
		printf(RED"./cub3d ./map.cub\n"NC);
		exit(1);
	}
	return (0);
}
