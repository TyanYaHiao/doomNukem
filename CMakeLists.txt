cmake_minimum_required(VERSION 3.13)
project(MapEditor C)

set(CMAKE_C_STANDARD 11)

include_directories(includes)
include_directories(lib/libft/includes)

add_executable(MapEditor
		includes/mapeditor.h
		srcs/mapeditor.c)
