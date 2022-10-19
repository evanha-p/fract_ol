/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:35:58 by evanha-p          #+#    #+#             */
/*   Updated: 2022/10/19 13:51:49 by evanha-p         ###   ########.fr       */
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
# define ZOOM 0.2

# define MANDELBROT 1
# define JULIA 2
# define BURNINGSHIP 3

# define CAST_JUMP 4
# define MAX_ITER 80

# define LEFT_MOUSE 1
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef enum e_bool
{
	false,
	true
}	t_bool;

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
	t_bool	l_mouse_pressed;
}	t_fract;

typedef struct s_var
{
	int		x;
	int		y;
	double	c_re;
	double	c_img;
	int		ret;
	int		color;
}	t_var;

void	iterate_screen(t_fract *fract);
int		mandelbrot_ship(double c_re, double c_img, int fractol);
void	init_values(t_fract *fract);
void	error_msg(char *msg);
void	check_mlx(t_mlx mlx);
int		picker(int fractal, double c_re, double c_img);
void	events(t_fract *fract);
int		mouse_button(int button, int x, int y, t_fract *fract);

#endif
