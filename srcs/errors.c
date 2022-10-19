/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:12:29 by evanha-p          #+#    #+#             */
/*   Updated: 2022/10/19 11:40:00 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	print_options(void)
{
	ft_putstr("Usage: ./fractol <fractal name here>\n");
	ft_putstr("------------OPTIONS------------\n");
	ft_putstr("mandelbrot = draw mandelbrot\n");
	ft_putstr("julia = draw julia\n");
	ft_putstr("burningship = draw burningship\n");
	ft_putstr("-------------------------------\n");
}

void	error_msg(char *msg)
{
	ft_putstr_fd(msg, 2);
	print_options();
	exit(0);
}

void	check_mlx(t_mlx mlx)
{
	if (!mlx.mlx_ptr)
		error_msg("Error: mlx_init failed\n");
	if (!mlx.win_ptr)
		error_msg("Error: failed to create a window\n");
	if (!mlx.img_ptr)
		error_msg("Error: failed to create a image\n");
	if (!mlx.char_ptr)
		error_msg("Error: failed to get image data\n");
}
