/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:46:09 by evanha-p          #+#    #+#             */
/*   Updated: 2022/10/19 14:27:46 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	zoom_in(int x, int y, t_fract *fract)
{
	t_var	v;

	v.c_re = (fract->x_start + ((double)x / IMG_W) * \
			(fract->x_end - fract->x_start));
	v.c_img = (fract->y_start + ((double)y / IMG_H) * \
			(fract->y_end - fract->y_start));
	fract->x_start = fract->x_start - ((fract->x_start - v.c_re) * ZOOM);
	fract->y_start = fract->y_start - ((fract->y_start - v.c_img) * ZOOM);
	fract->x_end = fract->x_end + ((v.c_re - fract->x_end) * ZOOM);
	fract->y_end = fract->y_end + ((v.c_img - fract->y_end) * ZOOM);
	iterate_screen(fract);
	mlx_put_image_to_window(fract->mlx.mlx_ptr, fract->mlx.win_ptr, \
			fract->mlx.img_ptr, 0, 0);
}

static	void	zoom_out(int x, int y, t_fract *fract)
{
	t_var	v;

	v.c_re = (fract->x_start + ((double)x / IMG_W) * \
			(fract->x_end - fract->x_start));
	v.c_img = (fract->y_start + ((double)y / IMG_H) * \
			(fract->y_end - fract->y_start));
	fract->x_start = fract->x_start + ((fract->x_start - v.c_re) * ZOOM);
	fract->y_start = fract->y_start + ((fract->y_start - v.c_img) * ZOOM);
	fract->x_end = fract->x_end - ((v.c_re - fract->x_end) * ZOOM);
	fract->y_end = fract->y_end - ((v.c_img - fract->y_end) * ZOOM);
	iterate_screen(fract);
	mlx_put_image_to_window(fract->mlx.mlx_ptr, fract->mlx.win_ptr, \
			fract->mlx.img_ptr, 0, 0);
}

int		mouse_button(int button, int x, int y, t_fract *fract)
{
	if (button == SCROLL_UP && x > 0 && x < IMG_W && y > 0 && y < IMG_H)
		zoom_in(x, y, fract);
	if (button == SCROLL_DOWN && x > 0 && x < IMG_W && y > 0 && y < IMG_H)
		zoom_out(x, y, fract);
	if (button == LEFT_MOUSE)
	{
		if (fract->l_mouse_pressed)
			fract->l_mouse_pressed = false;
		else
			fract->l_mouse_pressed = true;
	}
	return (0);
}

int		mouse_movement(int x, int y, t_fract *fract)
{
	if (x > 0 && x < IMG_W && y > 0 && y < IMG_H && fract->l_mouse_pressed)
	{
		fract->c_julian_re = (fract->x_start + ((double)x / IMG_W) * \
				(fract->x_end - fract->x_start));
		fract->c_julian_img = (fract->y_start + ((double)y / IMG_H) * \
				(fract->y_end - fract->y_start));
		iterate_screen(fract);
		mlx_put_image_to_window(fract->mlx.mlx_ptr, fract->mlx.win_ptr, \
				fract->mlx.img_ptr, 0, 0);
	}
	return (0);
}
