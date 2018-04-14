#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx/mlx.h"

# include <math.h>
# include <pthread.h>

# define WIDTH 1000
# define HEIGHT 800

# define THREADS 32

# define ITERATIONS 100

typedef void*                     (*t_func_fract) (void *);

typedef struct  s_complex
{
	double      re;
	double      im;
}               t_complex;

typedef struct  s_win
{
	void        *mlx;
	void        *win;
	void	    *img;
}               t_win;

typedef struct  s_fract
{
    int         num_fract;
    char        *name;
    double      min_re;
    double      max_re;
    double      min_im;
    double      max_im;
    double      re_factor;
    double      im_factor;
    double julia_im;
    double julia_re;
    int         julia_move;
    t_win       win;

}               t_fract;

typedef struct  s_data
{
    t_fract     fract;
    t_complex   c;
    int         y_start;
    int         y_end;
}               t_data;

int     key_hook(int keycode, t_fract *param);
int ft_mandelbrot(t_fract fract);
int ft_julia(t_fract fract);
int         mouse_hook(int button, int x, int y, t_fract *param);
float		get_red(int color);
float		get_green(int color);
float		get_blue(int color);
void        ft_clear_window(t_fract *param);
int ft_ship(t_fract fract);
void        ft_get_color(int x, int y, char **str, int iter);
void ft_init_fract(t_fract *fract);
int     ft_optimization(int x, int y);

#endif