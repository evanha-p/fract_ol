/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:00:18 by evanha-p          #+#    #+#             */
/*   Updated: 2022/10/19 13:30:56 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_program(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(EXIT_SUCCESS);
}

int	choose_fractol(char *str)
{
	if (ft_strequ(str, "mandelbrot"))
		return (MANDELBROT);
	if (ft_strequ(str, "julia"))
		return (JULIA);
	if (ft_strequ(str, "burningship"))
		return (BURNINGSHIP);
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
	t_var	v;

	v.y = 0;
	while (v.y < IMG_H)
	{
		v.x = 0;
		while (v.x < IMG_W)
		{
			v.c_re = (fract->x_start + ((double)v.x / IMG_W) * \
					(fract->x_end - fract->x_start));
			v.c_img = (fract->y_start + ((double)v.y / IMG_H) * \
					(fract->y_end - fract->y_start));
			v.ret = picker(fract->fractal, v.c_re, v.c_img);
			if (v.ret == 0)
				v.color = 0;
			else
				v.color = 0xffffff - (int)(v.ret * 0xffffff / MAX_ITER);	
			put_pxl(fract->mlx.char_ptr, v.x, v.y, v.color);	
			v.x++;
		}
		v.y++;
	}
	mlx_put_image_to_window(fract->mlx.mlx_ptr, fract->mlx.win_ptr, \
			fract->mlx.img_ptr, 0, 0);
}

int	main(int argc, char **argv)
{
	t_fract	fract;

	if (argc != 2)
		error_msg("Error: incorrect number of arguments\n");
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
	events(&fract);
	mlx_hook(fract.mlx.win_ptr, 17, 0, &close_program, &fract.mlx);
	mlx_loop(fract.mlx.mlx_ptr);
	return (0);
}
