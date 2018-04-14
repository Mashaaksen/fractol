#include "fractol.h"

void    *draw_ship(void *info)
{
    int x;
    t_data *data;
    t_complex   stat_z;
    t_complex   new_z;
    int         n;
    char        *px;
    int         p;

    data = (t_data *)info;
    px = mlx_get_data_addr(data->fract.win.img, &p, &p, &p);
    while (data->y_start < data->y_end)
    {
        x = 0;
        data->c.im = data->fract.max_im - (data->y_start * data->fract.im_factor);
        while (x < WIDTH)
        {
            data->c.re = data->fract.min_re + (x * data->fract.re_factor);
            stat_z.im = data->c.im;
            stat_z.re = data->c.re;
            n = 0;
            while (n < ITERATIONS)
            {
                new_z.re = stat_z.re * stat_z.re;
                new_z.im = stat_z.im * stat_z.im;
                if (new_z.re + new_z.im > 4)
                    break ;
                stat_z.im = 2 * fabs(stat_z.re * stat_z.im) + data->c.im;
                stat_z.re = new_z.re - new_z.im + data->c.re;
                n++;
            }
            if (new_z.re + new_z.im > 4)
                ft_get_color(x, data->y_start, &px, n);
            x++;
        }
        data->y_start++;
    }
    pthread_exit(NULL);
}

int ft_ship(t_fract fract)
{
    t_data      data[THREADS];
    pthread_t   pthread[THREADS];
    int i;

    i = 0;
    while (i < THREADS)
    {
        data[i].fract = fract;
        data[i].y_start = HEIGHT / THREADS * i;
        data[i].y_end = HEIGHT / THREADS * (i + 1);
        pthread_create(&pthread[i], NULL, draw_ship, (void *)&data[i]);
        i++;
    }
    i = 0;
    while (i < THREADS)
    {
        pthread_join(pthread[i], NULL);
        i++;
    }
    mlx_put_image_to_window(fract.win.mlx, fract.win.win, fract.win.img, 0,0);
    return (0);
}