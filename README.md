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
-lmlx -lXext -lX11 flags!  
  
</details>
<details>
<summary>not install</summary>
</details>
  
thank you! ⭐  
  
  
### usefull links  
[Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/raycasting.html)
