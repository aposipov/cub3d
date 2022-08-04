# cub3d

### Install minilibx
[MiniLibX from Paris students](https://github.com/42Paris/minilibx-linux)  
```
git clone https://github.com/42Paris/minilibx-linux.git && cd minilibx-linux && make
```
Manual install on Linux  
install libmlx.a
```
sudo cp libmlx.a /usr/local/lib 
```
install mlx.h and mlx_int.h
```
sudo mkdir /usr/local/include/mlx/ && sudo cp mlx.h mlx_int.h /usr/local/include/mlx/
```
install man file
```
sudo cp test_man/ /usr/local/
```
