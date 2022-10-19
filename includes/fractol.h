/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:35:58 by evanha-p          #+#    #+#             */
/*   Updated: 2022/10/19 11:23:05 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx.h"
# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

# define IMG_W 1000
# define IMG_H 1000

# define MANDELBROT 1
# define JULIA 2

# define CAST_JUMP 4
# define MAX_ITER 80

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*char_ptr;
	int		bpp;
	int		stride;
	int		endian;
}	t_mlx;

typedef struct s_fract
{
	double	x_start;
	double	x_end;
	double	y_start;
	double	y_end;
	t_mlx	mlx;
	int		fractal;
}	t_fract;

int		mandelbrot(double c_re, double c_img);
void	init_values(t_fract *fract);
void	error_msg(char *msg);
void	check_mlx(t_mlx mlx);

#endif
