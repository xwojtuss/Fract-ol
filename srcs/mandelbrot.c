/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkornato <wkornato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:46:25 by wkornato          #+#    #+#             */
/*   Updated: 2024/09/24 11:46:26 by wkornato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	display_mandelbrot_set(t_render render, double real, double imag)
{
	int			iter;
	t_complex	z;
	double		temp;

	z = (t_complex){0, 0};
	iter = 0;
	while (iter < render.max_iter)
	{
		if ((z.real * z.real + z.imaginary * z.imaginary) > BREAK_POINT)
			break ;
		temp = 2 * z.real * z.imaginary + imag;
		z.real = z.real * z.real - z.imaginary * z.imaginary + real;
		z.imaginary = temp;
		iter++;
	}
	return (iter);
}
