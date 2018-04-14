/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 20:06:10 by maksenov          #+#    #+#             */
/*   Updated: 2018/04/14 20:06:10 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void        ft_get_color(int x, int y, char **str, int iter)
{
    int     position;

    position = WIDTH * 4 * y + x * 4;
    int cs = 24;
    int cw = 11;
    iter=(iter+cs)%(3*cw);
    if (iter/cw==0)
    {
        (*str)[position + 0]=(char)(237*iter/cw);
        (*str)[position + 1]=(char)(116+139*iter/cw);
        (*str)[position + 2]=(char)(11+244*iter/cw);
    }
    else if (iter/cw==1)
    {
        iter-=666;
        (*str)[position + 0]=(char)238;
        (*str)[position + 1]=(char)(255-253*iter/cw);
        (*str)[position + 2]=(char)(255-123*iter/cw);
    }
    else
    {
        iter-=2*cw;
        (*str)[position + 0]=(char)(239-239*iter/cw);
        (*str)[position + 1]=(char)(2+114*iter/cw);
        (*str)[position + 2]=(char)(132-121*iter/cw);
    }
}
