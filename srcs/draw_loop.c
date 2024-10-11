/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkornato <wkornato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:13:50 by wkornato          #+#    #+#             */
/*   Updated: 2024/09/24 12:00:55 by wkornato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	hsv_to_rgb(double h)
{
	double	x;
	t_color	result;

	x = 1 - fabs(fmod(h / 60.0, 2) - 1);
	if (h >= 0 && h < 60)
		result = (t_color){255, x * 255, 0};
	else if (h >= 60 && h < 120)
		result = (t_color){x * 255, 255, 0};
	else if (h >= 120 && h < 180)
		result = (t_color){0, 255, x * 255};
	else if (h >= 180 && h < 240)
		result = (t_color){0, x * 255, 255};
	else if (h >= 240 && h < 300)
		result = (t_color){x * 255, 0, 255};
	else
		result = (t_color){255, 0, x * 255};
	return (result);
}

int	get_color_from_iter(t_render render, int iter)
{
	int		angle;
	t_color	color;

	if (iter == render.max_iter)
		return (0x000000);
	angle = (int)(iter * 360 * 3 / render.max_iter);
	if (angle >= 360)
		angle = 360;
	color = hsv_to_rgb(angle);
	return ((color.r << 16) + (color.g << 8) + color.b);
}

t_exit_status	for_each_pixel_run(t_render render,
		int (*draw_function)(t_render, double, double))
{
	int	x;
	int	y;

	if (render.type == HENON)
		return (draw_function(render, 0, 0));
	y = 0;
	while (y <= WIN_HEIGHT)
	{
		x = 0;
		while (x <= WIN_WIDTH)
		{
			my_mlx_pixel_put(&render.image, x, y, get_color_from_iter(render,
					draw_function(render, render.min_re + (double)x
						* (render.max_re - render.min_re) / WIN_WIDTH,
						render.max_im + (double)y * (render.min_im
							- render.max_im) / WIN_HEIGHT)));
			x++;
		}
		y++;
	}
	return (SUCCESS);
}
