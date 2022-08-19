cmake_minimum_required(VERSION 3.22)
project(cub3d C)

set(CMAKE_C_STANDARD 99)

include_directories(inc)
include_directories(./libft/inc)
add_subdirectory(./libft)

add_executable(cub3d src/main.c
		src/gnl/get_next_line.c src/gnl/get_next_line_utils.c
		src/init.c)

set(CMAKE_C_FLAGS  "-lmlx -lXext -lX11")
set(CMAKE_C_FLAGS_INIT "-Wall -Werror -Wextra")

target_link_libraries(cub3d libft
		/usr/local/lib/libmlx.a)