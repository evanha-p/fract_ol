/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:35:58 by evanha-p          #+#    #+#             */
/*   Updated: 2022/10/19 09:07:41 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "..libft/includes/libft.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

# define IMG_W 2000
# define IMG_H 2000

# define MANDELBROT 0
# define JULIA 1

typedef struct s_fract
{
	double	x_start;
	double	x_end;
	double	y_start;
	double	y_end;
	t_mlx	*mlx;
	int		fractal;
}	t_fract;

#endif
