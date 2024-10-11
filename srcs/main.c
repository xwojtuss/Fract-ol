/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkornato <wkornato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:46:23 by wkornato          #+#    #+#             */
/*   Updated: 2024/09/24 11:46:24 by wkornato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal	check_argument(int argc, char **argv)
{
	if (argc < 2)
		print_argument_options_and_exit();
	if (!ft_strcmp(argv[1], "Mandelbrot") && argc == 2)
		return (MANDELBROT);
	else if (!ft_strcmp(argv[1], "Julia") && argc == 2)
		return (JULIA);
	else if (!ft_strcmp(argv[1], "Burningship") && argc == 2)
		return (BURNINGSHIP);
	else
		print_argument_options_and_exit();
	return (NOT_SET);
}

int	main(int argc, char **argv)
{
	t_render	render;

	render.type = check_argument(argc, argv);
	initialize_render_structure(&render);
	mlx_mouse_hook(render.window_pointer, mouse_handler, &render);
	mlx_hook(render.window_pointer, KeyPress, KeyPressMask, on_keydown_handler,
		&render);
	mlx_hook(render.window_pointer, DestroyNotify, KeyPressMask,
		red_cross_handler, &render);
	display_fractal(render);
}
