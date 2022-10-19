/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:10:50 by evanha-p          #+#    #+#             */
/*   Updated: 2022/10/19 11:26:32 by evanha-p         ###   ########.fr       */
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
	}
	else
	{
		fract->x_start = -3;
		fract->x_end = 3;
		fract->y_start = -3;
		fract->y_end = 3;
	}
}
