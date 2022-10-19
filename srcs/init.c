/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:10:50 by evanha-p          #+#    #+#             */
/*   Updated: 2022/10/19 13:49:15 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_values(t_fract *fract)
{
	if (fract->fractal == MANDELBROT)
	{
		fract->x_start = -2;
		fract->x_end = 1;
		fract->y_start = -1;
		fract->y_end = 1;
		fract->l_mouse_pressed = false;
	}
	else
	{
		fract->x_start = -3;
		fract->x_end = 3;
		fract->y_start = -3;
		fract->y_end = 3;
		fract->l_mouse_pressed = false;
	}
}
