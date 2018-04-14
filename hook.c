#include "fractol.h"

void        ft_clear_window(t_fract *param)
{
    char *str;
    int p;
    str = mlx_get_data_addr(param->win.img, &p, &p, &p);
    ft_bzero(str, WIDTH*HEIGHT*4);
    mlx_put_image_to_window(param->win.mlx, param->win.win, param->win.img, 0,0);
}

int     key_hook(int keycode, t_fract *fract)
{
    if (keycode == 53 && fract)
        exit(0);
    else if (keycode == 12)
	{
        ft_clear_window(fract);
        fract->min_re = -2.4;
        fract->max_re = 2.4;
        fract->min_im = 2.0;
        fract->max_im = -2.0;
        fract->im_factor = (fract->max_im - fract->min_im) / (HEIGHT - 1);
        fract->re_factor = (fract->max_re - fract->min_re) / (WIDTH - 1);
        fract->julia_im = 0.6;
        fract->julia_re = -0.4;
        if (fract->num_fract == 1)
            ft_mandelbrot(*fract);
        else if (fract->num_fract == 2)
            ft_julia(*fract);
        else if (fract->num_fract == 3)
            ft_ship(*fract);
    }
    else if (keycode == 14 && fract->num_fract == 2)
    {
        fract->julia_move = (fract->julia_move == 1) ? 0 : 1;
    }
    return (0);
}

double interpolate(double start, double end, double interpolation)
{
    return start + ((end - start) * interpolation);
}

int         mouse_hook(int button, int x, int y, t_fract *param)
{
	if (button == 5)
	{
        ft_clear_window(param);
        double mouseRe = (double)x / (WIDTH / (param->max_re - param->min_re)) + param->min_re;
        double mouseIm = (double)y / (HEIGHT / (param->min_im - param->max_im)) + param->max_im;
        double interpolation = 0.9;
        param->min_re = interpolate(mouseRe, param->min_re, interpolation);
        param->min_im = interpolate(mouseIm, param->min_im, interpolation);
        param->max_re = interpolate(mouseRe, param->max_re, interpolation);
        param->max_im = interpolate(mouseIm, param->max_im, interpolation);
        param->im_factor = (param->max_im - param->min_im) / (HEIGHT - 1);
        param->re_factor = (param->max_re - param->min_re) / (WIDTH - 1);
        if (param->num_fract == 1)
            ft_mandelbrot(*param);
        else if (param->num_fract == 2)
            ft_julia(*param);
        else if (param->num_fract == 3)
            ft_ship(*param);

	}
    if (button == 4)
    {
        ft_clear_window(param);
        double mouseRe = (double)x / (WIDTH / (param->max_re - param->min_re)) + param->min_re;
        double mouseIm = (double)y / (HEIGHT / (param->min_im - param->max_im)) + param->max_im;
        double interpolation = 1.2;
        param->min_re = interpolate(mouseRe, param->min_re, interpolation);
        param->min_im = interpolate(mouseIm, param->min_im, interpolation);
        param->max_re = interpolate(mouseRe, param->max_re, interpolation);
        param->max_im = interpolate(mouseIm, param->max_im, interpolation);
        param->im_factor = (param->max_im - param->min_im) / (HEIGHT - 1);
        param->re_factor = (param->max_re - param->min_re) / (WIDTH - 1);
        if (param->num_fract == 1)
            ft_mandelbrot(*param);
        else if (param->num_fract == 2)
            ft_julia(*param);
        else if (param->num_fract == 3)
            ft_ship(*param);
    }
	return (0);
}