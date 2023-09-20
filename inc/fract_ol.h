/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groman-l <groman-l@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 22:55:49 by groman-l          #+#    #+#             */
/*   Updated: 2023/09/06 11:48:44 by groman-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "../miniLibX/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define SUCCESS	0
# define FALSE		0
# define TRUE		1
# define ERROR	   -1
# define E_EXIT		1
# define HIGH		1000
# define WIDTH		1000

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			l_len;
	int			end;
	double		m_x;
	double		m_y;
	int			max_iter;
	double		max_im;
	int			argc;
	char		*args;
}	t_fractol;

int		ft_exit(t_fractol *f);
void	render(t_fractol *f, int x, int y);
void	my_mlx_pixel_put(t_fractol *f, int x, int y, int color);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		fractol(t_fractol *f, double re, double im);

#endif