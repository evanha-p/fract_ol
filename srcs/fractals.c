/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:40:03 by evanha-p          #+#    #+#             */
/*   Updated: 2022/10/19 11:31:12 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mandelbrot(double c_re, double c_img)
{
	double z_re;
	double z_img;
	double temp;
	int n;

	z_re = c_re;
	z_img = c_img;
	n = 0;
	while (n < MAX_ITER)
	{
		if ((z_img * z_img + z_re * z_re) > 4)
			return (n);
		temp = z_img;
		z_img = z_re * z_img + z_re * z_img + c_img;
		z_re = z_re * z_re + temp * temp * (-1) + c_re;
		n++;
	}
	return (0);
}

int		picker(int fractal, double c_re, double c_img)
{
	if (fractal == MANDELBROT)
		return (mandelbrot(c_re, c_img));
	else
		return (0);
}
