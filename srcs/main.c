/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:00:18 by evanha-p          #+#    #+#             */
/*   Updated: 2022/10/19 11:23:22 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	choose_fractol(char *str)
{
	if (ft_strequ(str, "mandelbrot"))
		return (MANDELBROT);
	if (ft_strequ(str, "julia"))
		return (JULIA);
	else
		return (0);
}

void	put_pxl(char *char_ptr, int x, int y, int color)
{
	if (x < 0 || y < 0 || x >= IMG_W || y >= IMG_H)
		return;
	*(int *)(char_ptr + ((x + y * IMG_W) * CAST_JUMP)) = color; 
}

void	iterate_screen(t_fract *fract)
{
	int		x;
	int		y;
	double	c_re;
	double	c_img;
	int		ret;
	int		color;

	y = 0;
	while (y < IMG_H)
	{
		x = 0;
		while (x < IMG_W)
		{
			c_re = (fract->x_start + ((double)x / IMG_W) * (fract->x_end - fract->x_start));
			c_img = (fract->y_start + ((double)y / IMG_H) * (fract->y_end - fract->y_start));
			ret = mandelbrot(c_re, c_img);
			if (ret == 0)
				color = 0;
			else
				color = 0xffffff - (int)(ret * 0xffffff / MAX_ITER);	
			put_pxl(fract->mlx.char_ptr, x, y, color);	
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->mlx.mlx_ptr, fract->mlx.win_ptr, fract->mlx.img_ptr, 0, 0);
}

int	main(int argc, char **argv)
{
	t_fract	fract;

	if (argc != 2)
		error_msg("Usage: ./fractol <fractal name here>\n");
	fract.fractal = choose_fractol(argv[1]);
	if (fract.fractal == 0)
		error_msg("Error: fractal not found\n");
	fract.mlx.mlx_ptr = mlx_init();
	fract.mlx.win_ptr = mlx_new_window(fract.mlx.mlx_ptr, IMG_W, \
			IMG_H, "fractol");
	fract.mlx.img_ptr = mlx_new_image(fract.mlx.mlx_ptr, IMG_W, IMG_H);
	fract.mlx.char_ptr = mlx_get_data_addr(fract.mlx.img_ptr, &fract.mlx.bpp, \
			&fract.mlx.stride, &fract.mlx.endian);
	check_mlx(fract.mlx);
	init_values(&fract);
	iterate_screen(&fract);
	mlx_loop(fract.mlx.mlx_ptr);
	return (0);
}
