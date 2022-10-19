/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:40:03 by evanha-p          #+#    #+#             */
/*   Updated: 2022/10/19 14:34:08 by evanha-p         ###   ########.fr       */
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

int		julia(double c_re, double c_img, t_fract fract)
{
	double	z_re;
	double	z_img;
	double	temp;
	int		n;

	z_re = c_re;
	z_img = c_img;
	n = 0;
	while (n < MAX_ITER)
	{
		if ((z_img *z_img + z_re * z_re) > 4)
			return (n);
		temp = z_img;
		z_img = 2 * (z_re * z_img) + fract.c_julian_img;
		z_re = z_re * z_re + temp * temp * (-1) + fract.c_julian_re;
		n++;
	}
	return (0);
}

int		picker(t_fract fract, double c_re, double c_img)
{
	if (fract.fractal == MANDELBROT)
		return (mandelbrot_ship(c_re, c_img, MANDELBROT));
	if (fract.fractal == BURNINGSHIP)
		return (mandelbrot_ship(c_re, c_img, BURNINGSHIP));
	if (fract.fractal == JULIA)
		return (julia(c_re, c_img, fract));
	else
		return (0);
}
