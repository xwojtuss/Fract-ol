/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkornato <wkornato@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:46:17 by wkornato          #+#    #+#             */
/*   Updated: 2024/10/11 23:59:54 by wkornato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_handler(int key_code, int x, int y, t_render *render)
{
	if (key_code == MOUSE_SCROLL_UP)
		zoom_into_point(render, x, y);
	else if (key_code == MOUSE_SCROLL_DOWN)
	{
		zoom_image(render, 2);
		render->max_iter -= 10;
	}
	else if (key_code == MOUSE_CLICK && (render->type == JULIA
			|| render->type == HENON))
	{
		render->c_real = (2 * x / (double)WIN_WIDTH) - (double)1;
		render->c_imag = (2 * y / (double)WIN_HEIGHT) - (double)1;
	}
	else
		return (SUCCESS);
	display_fractal(*render);
	return (SUCCESS);
}

int	on_keydown_handler(int key_code, t_render *render)
{
	if (key_code == XK_Escape)
		close_window_and_exit(render, SUCCESS);
	else if (key_code == XK_w || key_code == XK_W || key_code == XK_Up)
		move_image(render, 0.1, DIR_UP);
	else if (key_code == XK_s || key_code == XK_S || key_code == XK_Down)
		move_image(render, 0.1, DIR_DOWN);
	else if (key_code == XK_a || key_code == XK_A || key_code == XK_Left)
		move_image(render, 0.1, DIR_LEFT);
	else if (key_code == XK_d || key_code == XK_D || key_code == XK_Right)
		move_image(render, 0.1, DIR_RIGHT);
	else
		return (SUCCESS);
	display_fractal(*render);
	return (SUCCESS);
}

int	red_cross_handler(t_render *render)
{
	close_window_and_exit(render, SUCCESS);
	return (SUCCESS);
}
