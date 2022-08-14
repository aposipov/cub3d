cmake_minimum_required(VERSION 3.22)
project(cub3d C)

set(CMAKE_C_STANDARD 99)

include_directories(inc)
include_directories(./libft/inc)
add_subdirectory(./libft)

add_executable(cub3d src/main.c)

#set(CMAKE_C_FLAGS  "-lreadline")

target_link_libraries(cub3d libft)