cmake_minimum_required(VERSION 3.22)
project(cub3d C)

set(CMAKE_C_STANDARD 99)

include_directories(inc)
include_directories(./libft/inc)
add_subdirectory(./libft)

add_executable(cub3d src/main.c
		src/gnl/get_next_line.c src/gnl/get_next_line_utils.c
		src/init.c src/start.c
		src/parsing/parser.c src/parsing/pars_walls.c src/parsing/pars_fc.c
		src/parsing/player.c src/parsing/pars_map.c
		src/minimap.c src/hooks/key_hooks.c
		src/raycasting/dda_calculations.c src/raycasting/draw_textures.c src/parsing/check.c src/hooks/mouse_hooks.c)

set(CMAKE_C_FLAGS  "-lm -lmlx -lXext -lX11")
set(CMAKE_C_FLAGS_INIT "-Wall -Werror -Wextra")

target_link_libraries(cub3d libft
		/usr/local/lib/libmlx.a)