## cub3d
First-person 3D representation of a maze using raycasting, similar to Wolfenstein 3D 🎮 (1992).
  
### install minilibx on linux or launch in directory
<details>
<summary>install guide</summary>  
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

edit header files in test/main.c and test/new_window.c <mlx/mlx.h> <mlx/mlx_int.h> <- your mlx.h path 
test for minilibx  
```
cd test && gcc main.c -lmlx -lXext -lX11 -o test1 && gcc new_win.c -lmlx -lXext -lX11 -o test2
```  
correct compile flags  
`gcc/clang -Wall -Wextra -Werror main.c/main.o -lmlx -lXext -lX11 -o start`  
  
</details>
  
<details>
<summary>launch in direcory</summary>
<br>
in file edit "../mlx/mlx.h" <- path to mlx.h  
  
`gcc test.c -L ../[Path to libmlx.a] -lmlx -lXext -lX11`  
</details>
  
thank you! ⭐  
  
  
### usefull links
[Coding time Video](https://www.youtube.com/watch?v=vK6_Hz6O8iA)  
[video mvenmo part1](https://www.youtube.com/watch?v=Ui7qFpeqa3c&t=0s)  
[video mvenmo part2](https://www.youtube.com/watch?v=XWCHl0rpBj4&t=0s)  
[Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/raycasting.html)
