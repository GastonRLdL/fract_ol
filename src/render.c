/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groman-l <groman-l@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:02:23 by groman-l          #+#    #+#             */
/*   Updated: 2023/10/19 12:22:23 by groman-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../inc/fract_ol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < (n - 1))
		i++;
	if (n == 0)
		return (0);
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

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

static int	julia(double zx, double zy, t_fractol *f)
{
	int		i;
	double	tmp;

	i = -1;
	tmp = 0;
	while (zx * zx + zy * zy <= 4.0 && ++i < f->max_iter)
	{
		tmp = 2 * zx * zy + f->m_y;
		zx = zx * zx - zy * zy + f->m_x;
		zy = tmp;
	}
	return (i);
}

int	fractol(t_fractol *f, double re, double im)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (f->args[len])
		len++;
	f->args[len] = '\0';
	if (!ft_strncmp(f->args, "mandelbrot", -1))
		i = mandelbrot(re, im, f);
	else if (!ft_strncmp(f->args, "julia", -1))
		i = julia(re, im, f);
	else
	{
		write(1, "it's -mandelbrot-\n", 17);
		write(1, "or -julia-\n", 11);
		ft_exit(f);
	}
	return (i);
}

int	render(t_fractol *f, int x, int y)
{
	double	re;
	double	im;
	int		i;

	f->max_iter = 100;
	mlx_clear_window(f->mlx, f->win);
	while (++y < HIGH)
	{
		x = -1;
		while (++x < WIDTH)
		{
			re = f->min_re + (double)x * (f->max_re - (f->min_re)) / WIDTH;
			im = f->max_im + (double)y * (f->min_im - f->max_im) / HIGH;
			i = fractol(f, re, im);
			if (i < f->max_iter)
				my_mlx_pixel_put(f, x, y, (i * 0xADD8E6));
			else
				my_mlx_pixel_put(f, x, y, 0x000000);
		}
	}
	mlx_put_image_to_window (f->mlx, f->win, f->img, 0, 0);
	return (SUCCESS);
}
