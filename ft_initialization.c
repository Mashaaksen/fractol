#include "fractol.h"

void ft_init_fract(t_fract *fract)
{
    fract->min_re = -2.4;
    fract->max_re = 2.4;
    fract->min_im = 2.0;
    fract->max_im = -2.0;
    fract->julia_move = 1;
    fract->im_factor = (fract->max_im - fract->min_im) / (HEIGHT - 1);
    fract->re_factor = (fract->max_re - fract->min_re) / (WIDTH - 1);
    fract->julia_im = 0.6;
    fract->julia_re = -0.4;
}

