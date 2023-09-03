/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groman-l <groman-l@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:02:23 by groman-l          #+#    #+#             */
/*   Updated: 2023/09/03 15:46:22 by groman-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

static int	mandelbrot(double cr, double ci, t_fractol *f)
{
	int		i;
	double	zx;
	double	zy;
	double	tmp;

	i = -1;
	zx = 0;
	zy = 0;
	tmp = 0;
	while (zx * zx + zy * zy <= 4.0 && ++i < f->max_iter)
	{
		tmp = zx * zx - zy * zy + cr;
		zy = 2 * zx * zy + ci;
		zx = tmp;
	}
	return (i);
}

static int	fractol(t_fractol *f, double re, double im)
{
	int	i;

	i = 0;
	if (f->type == 8)
		i = mandelbrot(re, im, f);
	else if (f->type == 0)
		i = 0;
	return (i);
}

void	render(t_fractol *f, int x, int y)
{
	double	re;
	double	im;
	double	max_im;
	int		i;

	f->max_iter = 100;
	f->type = 8;
	mlx_clear_window(f->mlx, f->win);
	max_im = -2.0 + (2.0 - (-2.0)) * HIGH / WIDTH;
	while (++y < HIGH)
	{
		x = -1;
		while (++x < WIDTH)
		{
			re = -2.0 + (double)x * (2.0 - (-2.0)) / WIDTH;
			im = max_im + (double)y * (-2.0 - 2.0) / HIGH;
			i = fractol(f, re, im);
			if (i < f->max_iter)
				my_mlx_pixel_put(f, x, y, (i * 0xADD8E6));
			else
				my_mlx_pixel_put(f, x, y, 0x000000);
		}
	}
	mlx_put_image_to_window (f->mlx, f->win, f->img, 0, 0);
}