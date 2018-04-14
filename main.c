#include "fractol.h"

void    ft_usage(void)
{
	char *first;

	first = "Usage: ./fractol [Name of the fractal: Mandelbrot | Julia | 3]\n";
	write(1, first, ft_strlen(first));
	write(1, "\t1. Mandelbrot\n", ft_strlen("\t1. Mandelbrot\n"));
    write(1, "\t2. Julia\n", ft_strlen("\t2. Julia\n"));
    write(1, "\t3. Ship\n", ft_strlen("\t3. Ship\n"));
    exit(1);
}

int         mouse_move(int x, int y, t_fract *param)
{
    if (param->julia_move)
    {
        param->julia_im = param->max_im - (y * param->im_factor);
        param->julia_re = param->min_re + (x * param->re_factor);
        ft_clear_window(param);
        ft_julia(*param);
    }
    return (0);
}

int     exit_hook(t_fract *fract)
{
    exit(0);
}

void ft_create_win(t_fract fract)
{
    fract.win.mlx = mlx_init();
    fract.win.win = mlx_new_window(fract.win.mlx, WIDTH, HEIGHT, fract.name);
    fract.win.img = mlx_new_image(fract.win.mlx, WIDTH, HEIGHT);
    ft_init_fract(&fract);
    mlx_key_hook(fract.win.win, key_hook, (void *)&fract);
    mlx_mouse_hook(fract.win.win, mouse_hook, (void *)&fract);
    mlx_hook(fract.win.win, 17, 0, exit_hook, (void *)&fract);
    if (fract.num_fract == 1)
        ft_mandelbrot(fract);
    else if (fract.num_fract == 2)
        ft_julia(fract);
    else if (fract.num_fract == 3)
        ft_ship(fract);
    if (fract.num_fract == 2)
        mlx_hook(fract.win.win, 6, 0, mouse_move, (void *)&fract);
    mlx_loop(fract.win.mlx);
}

int main(int ac, char **av)
{
    t_fract fract;

    if (ac > 1 && !ft_strcmp(av[1], "Mandelbrot"))
	    fract.num_fract = 1;
    else if (ac > 1 && !ft_strcmp(av[1], "Julia"))
        fract.num_fract = 2;
    else if (ac > 1 && !ft_strcmp(av[1], "Ship"))
        fract.num_fract = 3;
    else
        ft_usage();
    fract.name = av[1];
    ft_create_win(fract);
    return 0;
}