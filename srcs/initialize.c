/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkornato <wkornato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:35:33 by wkornato          #+#    #+#             */
/*   Updated: 2024/09/24 12:13:33 by wkornato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	assign_start_pos(t_render *render, double min_re, double max_re,
		double min_im)
{
	render->min_re = min_re;
	render->max_re = max_re;
	render->min_im = min_im;
	render->max_im = render->min_im + (render->max_re - render->min_re)
		* WIN_HEIGHT / WIN_WIDTH;
}

void	init_complex_numbers(t_render *render)
{
	if (render->type == JULIA)
		assign_start_pos(render, -2.0, 2.0, -1.2);
	else if (render->type == BURNINGSHIP)
	{
		assign_start_pos(render, -2.5, 1.5, 0.7);
		render->max_im = render->min_im - (render->max_re - render->min_re)
			* WIN_HEIGHT / WIN_WIDTH;
	}
	else
		assign_start_pos(render, -2.5, 1.5, -1.4);
	render->max_iter = MAX_ITER_COUNT;
	render->c_imag = 0.0;
	render->c_real = 0.0;
}

void	initialize_render_structure(t_render *render)
{
	render->mlx_pointer = mlx_init();
	if (!render->mlx_pointer)
		close_window_and_exit(render, MLX_INIT_ERROR);
	render->window_pointer = mlx_new_window(render->mlx_pointer, WIN_WIDTH,
			WIN_HEIGHT, "Fract-ol");
	if (!render->window_pointer)
		close_window_and_exit(render, MLX_WIN_ERROR);
	render->image.image_pointer = mlx_new_image(render->mlx_pointer, WIN_WIDTH,
			WIN_HEIGHT);
	if (!render->image.image_pointer)
		close_window_and_exit(render, MLX_IMG_ERROR);
	render->image.address = mlx_get_data_addr(render->image.image_pointer,
			&render->image.bits_per_pixel, &render->image.line_length,
			&render->image.endian);
	if (!render->image.address)
		close_window_and_exit(render, MLX_IMG_ERROR);
	init_complex_numbers(render);
}
