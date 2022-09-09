#!/bin/bash

RED='\033[4;31m'
GREEN='\033[0;32m'
YELLOW="\033[33m"
BLUE="\033[34m"
MAGENTA="\033[35m"
CYAN="\033[36m"
BLINK='\033[5m'
NC='\033[0;0m'

echo -e "${CYAN}<----------ARG CASES---------->${NC}"
echo "./cub3D"
./cub3D;
echo "./cub3D ./maps ./maps"
./cub3D ./maps ./maps;

echo -e "${CYAN}<----------PATH CASES---------->${NC}"
echo "./cub3D ./maps/map"
./cub3D ./maps/map;
echo "./cub3D ./maps/"
./cub3D ./maps/;
echo "./cub3D ./maps/test0.c"
./cub3D ./maps/test0.c;

echo -e "${CYAN}<----------FILE CASES---------->${NC}"
echo "./cub3D ./test/map_dir.cub"
./cub3D ./test/map_dir.cub;

echo -e "${CYAN}<----------NSWE CASES---------->${NC}"
echo -e "${BLUE}test two NO${NC}"
./cub3D ./test/two_NO.cub;
echo -e "${BLUE}test only four SO${NC}"
./cub3D ./test/four_SO.cub;
echo -e "${BLUE}test three textures${NC}"
./cub3D ./test/three_text.cub;
echo -e "${BLUE}test no textures${NC}"
./cub3D ./test/no_text.cub;
echo -e "${BLUE}test bad key texture${NC}"
./cub3D ./test/bad_key_text.cub;
echo -e "${BLUE}test bad path to xpm${NC}"
./cub3D ./test/bad_path_xpm.cub;

echo -e "${CYAN}<----------F/C CASES---------->${NC}"
echo -e "${BLUE}test no F/C${NC}"
./cub3D ./test/no_fc.cub;
echo -e "${BLUE}test two F${NC}"
./cub3D ./test/two_f.cub;
echo -e "${BLUE}test three F/C${NC}"
./cub3D ./test/three_fc.cub;
echo -e "${BLUE}test bad key F/C${NC}"
./cub3D ./test/bad_key_fc.cub;
echo -e "${BLUE}test bad color${NC}"
./cub3D ./test/bad_color.cub;

echo -e "${CYAN}<----------MAP CASES---------->${NC}"
echo -e "${BLUE}test no map${NC}"
./cub3D ./test/no_map.cub;
echo -e "${BLUE}test no top wall${NC}"
./cub3D ./test/no_top_w.cub;
echo -e "${BLUE}test no left wall${NC}"
./cub3D ./test/no_left_w.cub;
echo -e "${BLUE}test no right wall${NC}"
./cub3D ./test/no_right_w.cub;
echo -e "${BLUE}test no down wall${NC}"
./cub3D ./test/no_down_w.cub;
echo -e "${BLUE}test no one symbol top wall${NC}"
./cub3D ./test/no_top_w1.cub;
echo -e "${BLUE}test no one symbol down wall${NC}"
./cub3D ./test/no_down_w1.cub;
echo -e "${BLUE}test bad symbol in map${NC}"
./cub3D ./test/bad_symbol_m.cub;
echo -e "${BLUE}test two player position${NC}"
./cub3D ./test/two_pl_pos.cub;
echo -e "${BLUE}test no player position${NC}"
./cub3D ./test/no_pl_pos.cub;
echo -e "${BLUE}test one symbol map${NC}"
./cub3D ./test/one_s_m.cub;

echo -e "${CYAN}<----------THE END---------->${NC}"
