/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_controllably.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkornato <wkornato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:46:12 by wkornato          #+#    #+#             */
/*   Updated: 2024/09/24 11:46:13 by wkornato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	close_window_and_exit(t_render *render, t_exit_status code)
{
	if (render->mlx_pointer && render->window_pointer)
	{
		if (render->image.image_pointer)
			mlx_destroy_image(render->mlx_pointer, render->image.image_pointer);
		mlx_clear_window(render->mlx_pointer, render->window_pointer);
		mlx_destroy_window(render->mlx_pointer, render->window_pointer);
	}
	if (render->mlx_pointer)
		mlx_destroy_display(render->mlx_pointer);
	if (render->mlx_pointer)
		free(render->mlx_pointer);
	exit(code);
}

void	print_argument_options_and_exit(void)
{
	ft_putstr("Error: wrong arguments\n");
	ft_putstr("Possible arguments:\n");
	ft_putstr("Mandelbrot\n");
	ft_putstr("Julia\n");
	ft_putstr("Burningship\n");
	exit(FAILURE);
}
