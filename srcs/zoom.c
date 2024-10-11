/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkornato <wkornato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:51:07 by wkornato          #+#    #+#             */
/*   Updated: 2024/09/24 11:53:53 by wkornato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_image(t_render *render, double zoom_amount)
{
	double	real_middle;
	double	imag_middle;

	real_middle = render->min_re - render->max_re;
	imag_middle = render->max_im - render->min_im;
	render->max_re = render->max_re + (real_middle - zoom_amount * real_middle)
		/ 2;
	render->min_re = render->max_re + zoom_amount * real_middle;
	render->min_im = render->min_im + (imag_middle - zoom_amount * imag_middle)
		/ 2;
	render->max_im = render->min_im + zoom_amount * imag_middle;
}

void	move_image(t_render *render, double move_amount, int direction)
{
	double	real_middle;
	double	imag_middle;

	real_middle = render->max_re - render->min_re;
	imag_middle = render->max_im - render->min_im;
	if (ft_abs(direction) == DIR_RIGHT)
	{
		render->min_re += move_amount * real_middle * direction / DIR_RIGHT;
		render->max_re += move_amount * real_middle * direction / DIR_RIGHT;
	}
	if (ft_abs(direction) == DIR_DOWN)
	{
		render->min_im -= move_amount * imag_middle * direction / DIR_DOWN;
		render->max_im -= move_amount * imag_middle * direction / DIR_DOWN;
	}
}

void	zoom_into_point(t_render *render, int x, int y)
{
	int	x_dir;
	int	y_dir;

	zoom_image(render, 0.5);
	x -= WIN_WIDTH / 2;
	y -= WIN_HEIGHT / 2;
	x_dir = ((x < 0) * -2 + 1);
	y_dir = ((y < 0) * -2 + 1);
	move_image(render, (double)x * x_dir / WIN_WIDTH, DIR_RIGHT * x_dir);
	move_image(render, (double)y * y_dir / WIN_HEIGHT, DIR_DOWN * y_dir);
	render->max_iter += 10;
}
