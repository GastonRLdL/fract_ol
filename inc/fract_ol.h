/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groman-l <groman-l@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 22:55:49 by groman-l          #+#    #+#             */
/*   Updated: 2023/09/02 01:39:05 by groman-l         ###   ########.fr       */
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
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		l_len;
	int		end;
	int		m_x;
	int		m_y;
}	t_fractol;

#endif