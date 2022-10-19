/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:40:03 by evanha-p          #+#    #+#             */
/*   Updated: 2022/10/19 12:17:43 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mandelbrot_ship(double c_re, double c_img, int fractol)
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
		if (fractol == BURNINGSHIP)
		{
			z_re = fabs(z_re);
			z_img = fabs(z_img);
		}
		temp = z_img;
		z_img = 2 * (z_re * z_img) + c_img;
		z_re = z_re * z_re + temp * temp * (-1) + c_re;
		n++;
	}
	return (0);
}

int		picker(int fractal, double c_re, double c_img)
{
	if (fractal == MANDELBROT)
		return (mandelbrot_ship(c_re, c_img, MANDELBROT));
	if (fractal == BURNINGSHIP)
		return (mandelbrot_ship(c_re, c_img, BURNINGSHIP));
	else
		return (0);
}
