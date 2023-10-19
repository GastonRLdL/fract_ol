/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   fract_ol.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: groman-l <groman-l@student.42barcelona.	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/09/01 21:34:47 by groman-l		  #+#	#+#			 */
/*   Updated: 2023/10/18 15:31:43 by groman-l		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <stdio.h>
#include "../inc/fract_ol.h"

int	ft_exit(t_fractol *f)
{
	(void)f;
	if (f->argc > 2 || f->argc == 1)
	{
		write(1, "Error, invali arguments\n", 24);
		write(1, "is -mandelbrot-\n", 16);
		write(1, "or -julia-\n", 11);
	}
	exit ((write(1, "Close Fractol\n", 14) * 0));
}

int	ft_key(int key, t_fractol *f)
{
	if (key == 53)
		ft_exit(f);
	if (key == 4)
	{
		write(1, "up\n", 3);
		f->max_im *= 1.1;
	}
	return (SUCCESS);
	
}

int	ft_mouse(int key, int x, int y, t_fractol *f)
{
	f->cen_re = f->min_re - f->max_re;
	f->cen_im = f->max_im - f->min_im;
	if (key == 1)
	{
		f->m_x = -2.0 + (double)x * (2.0 - (-2.0)) / WIDTH;
		f->m_y = f->max_im + (double)y * (-2.0 - f->max_im) / WIDTH;
	}
	if (key == 4)
	{
		f->max_re = f->max_re + (f->cen_re - 1.1 * f->cen_re) / 2;
		f->min_re = f->max_re + 1.1 * f->cen_re;
		f->min_im = f->min_im + (f->cen_im - 1.1 * f->cen_im) / 2;
		f->max_im = f->min_im + 1.1 * f->cen_im;
	}
	if (key == 5)
	{
		f->max_re = f->max_re + (f->cen_re - 0.9 * f->cen_re) / 2;
		f->min_re = f->max_re + 0.9 * f->cen_re;
		f->min_im = f->min_im + (f->cen_im - 0.9 * f->cen_im) / 2;
		f->max_im = f->min_im + 0.9 * f->cen_im;
	}
	return (render(f, -1, -1));
}

void	my_mlx_pixel_put(t_fractol *f, int x, int y, int color)
{
	char	*dst;

	dst = f->addr + (y * f->l_len + x * (f->bpp / 8));
	*(unsigned int *)dst = color;
}

int	main(int ac, char **av)
{
	t_fractol	f;

	f.argc = ac;
	if (ac > 2 || ac == 1)
		ft_exit(&f);
	f.args = av[1];
	f.addr = NULL;
	f.l_len = 0;
	f.bpp = 0;
	f.mlx = mlx_init();
	f.win = mlx_new_window(f.mlx, HIGH, WIDTH, "fract_ol");
	f.img = mlx_new_image(f.mlx, HIGH, WIDTH);
	f.addr = mlx_get_data_addr(f.img, &f.bpp, &f.l_len, &f.end);
	f.min_re = -2.0;
	f.max_re = 2.0;
	f.min_im = -2.0;
	f.max_im = f.min_re + (f.max_re - (f.min_re)) * HIGH / WIDTH;
	render(&f, -1, -1);
	mlx_put_image_to_window(f.mlx, f.win, f.img, 0, 0);
	mlx_hook (f.win, 17, 0, ft_exit, &f);
	mlx_key_hook (f.win, ft_key, &f);
	mlx_mouse_hook (f.win, ft_mouse, &f);
	mlx_loop (f.mlx);
	return (SUCCESS);
}
