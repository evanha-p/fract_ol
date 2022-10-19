/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:03:18 by evanha-p          #+#    #+#             */
/*   Updated: 2022/10/19 14:55:01 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	button_press(int button, t_fract *fract)
{
	if (button == ESC)
		close_program(&fract->mlx);
	return (0);
}

void	events(t_fract *fract)
{
	mlx_hook(fract->mlx.win_ptr, 4, 0, mouse_button, fract);
	mlx_hook(fract->mlx.win_ptr, 6, 0, mouse_button, fract);
	mlx_hook(fract->mlx.win_ptr, 6, 0, mouse_movement, fract);
	mlx_hook(fract->mlx.win_ptr, 2, 0, button_press, fract);
}
