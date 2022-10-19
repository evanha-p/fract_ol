/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:03:18 by evanha-p          #+#    #+#             */
/*   Updated: 2022/10/19 13:34:17 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	events(t_fract *fract)
{
	mlx_hook(fract->mlx.win_ptr, 4, 0, mouse_button, fract);
	mlx_hook(fract->mlx.win_ptr, 6, 0, mouse_button, fract);
	/*mlx_hook(fract->mlx.win_ptr, 6, 0, mouse_movement, fract);*/
	/*mlx_hook(fract->mlx.win_ptr, 1L << 0, button_press, fract);*/
}
