# cub3d

### Install minilibx on linux
<details>
<summary>Guide</summary>  
<br>
  
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
install man1 and man3 file
```
sudo cp man/ /usr/local/
```   
test for minilibx  
```
cd test && gcc main.c -lmlx -lXext -lX11 -o test1 && gcc new_win.c -lmlx -lXext -lX11 -o test2
```  
edit header files in main.c and new_window.c <mlx/mlx.h> <mlx/mlx_int.h>  

correct compile flags  
`gcc/clang -Wall -Wextra -Werror main.c/main.o -lmlx -lXext -lX11 -o start`  
  
</details>
<details>
<summary>launch in direcory</summary>
  
in file edit "../mlx/mlx.h" <- path to mlx.h  
  
gcc test.c -L ../[Path to libmlx.a] -lmlx -lXext -lX11  
</details>
  
thank you! ⭐  
  
  
### usefull links  
[Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/raycasting.html)
