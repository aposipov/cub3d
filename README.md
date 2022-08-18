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
  
## 📌 usefull links 
[Coding time Video](https://www.youtube.com/watch?v=vK6_Hz6O8iA)  
[video mvenmo part1](https://www.youtube.com/watch?v=Ui7qFpeqa3c&t=0s)  
[video mvenmo part2](https://www.youtube.com/watch?v=XWCHl0rpBj4&t=0s)  
[42 docs Minilibx](https://harm-smits.github.io/42docs/libs/minilibx)  
[mlx tutorial to create image](https://github.com/Gontjarow/MiniLibX/blob/master/docs/mlx-tutorial-create-image.md)  
[Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/raycasting.html)  
[Рейкастинг для самых маленьких: геймдев на реальных проектах](https://proglib.io/p/raycasting-for-the-smallest)  
[Пишем шутер от первого лица в консоли! Как работает псевдо-3d графика в играх?](http://ilinblog.ru/article.php?id_article=49)  
[cub3d - 42, в котором мы узнаем о Raycasting и пытаемся воссоздать оригинальную 3D-игру Wolfenstein](https://www.mokairui.com/opensource/ru/6149d14c5f206938f5123d54.html)  
[Немного про исправление рыбьего глаза](https://permadi.com/1996/05/ray-casting-tutorial-8/)  
[Легкая реализация куба](https://github.com/OneLoneCoder/CommandLineFPS/blob/master/CommandLineFPS.cpp)  
