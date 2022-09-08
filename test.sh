#!/bin/bash

echo "test bad file and bad path";
./cub3D ./maps/bad_maps/map;
echo "test empty file";
./cub3D ./maps/bad_maps/empty.cub;
echo "test no fc no map";
./cub3D ./maps/bad_maps/no_fc_no_map.cub;
echo "test no map";
./cub3D ./maps/bad_maps/no_map.cub;
echo "test bad map no wall";
./cub3D ./maps/bad_maps/bad_map.cub;
echo "test bad symboll in map";

echo "test bad map no wall";

Error: wrong texture file
 another textures