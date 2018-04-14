cmake_minimum_required(VERSION 3.8)
project(fractol)

set(CMAKE_C_STANDARD 99)


include_directories(includes libft) # headers

link_directories(libft) # libraries

set(SOURCE_FILES main.c fractol.h ft_mandelbrot.c hook.c ft_get_color.c ft_julia.c ft_ship.c ft_initialization.c ft_calculating.c)
add_executable(fractol ${SOURCE_FILES})

target_link_libraries(fractol libft.a) # linkage