//
// Created by user on 14.08.22.
//

#include "cub3d.h"

static void open_path(char const *path)
{
	int fd;

	fd = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		printf("file not exist\n");
	close(fd);
}

static void check_path(char const *path)
{
	int	i;

	i = 0;
	while (path[i])
		i++;
	if (!(path[i - 1] == 'b' && path[i - 2] == 'u' && path[i - 3] == 'c' && \
	path[i - 4] == '.' && path[i -5] >= 48))
	{
		printf("check you path! -> %s\n", path);
		exit(0);
	}
	open_path(path);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		check_path(argv[1]);

	}
	else
	{
		printf("should be argument the path to map!\n");
		printf("./cub3d ./map.cub\n");
	}
	return (0);
}