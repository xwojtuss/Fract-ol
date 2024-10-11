/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkornato <wkornato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:40:33 by wkornato          #+#    #+#             */
/*   Updated: 2024/09/24 11:49:10 by wkornato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display_fractal(t_render render)
{
	t_exit_status	exit_status;

	exit_status = FAILURE;
	if (render.type == MANDELBROT)
		exit_status = for_each_pixel_run(render, display_mandelbrot_set);
	else if (render.type == JULIA)
		exit_status = for_each_pixel_run(render, display_julia_set);
	else if (render.type == BURNINGSHIP)
		exit_status = for_each_pixel_run(render, display_burningship_set);
	mlx_clear_window(render.mlx_pointer, render.window_pointer);
	mlx_put_image_to_window(render.mlx_pointer, render.window_pointer,
		render.image.image_pointer, 0, 0);
	mlx_loop(render.mlx_pointer);
	close_window_and_exit(&render, exit_status);
}
