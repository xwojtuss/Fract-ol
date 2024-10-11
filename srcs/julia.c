/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkornato <wkornato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:46:20 by wkornato          #+#    #+#             */
/*   Updated: 2024/09/24 11:48:57 by wkornato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	display_julia_set(t_render render, double real, double imag)
{
	int			iter;
	t_complex	z;
	double		temp;

	z = (t_complex){real, imag};
	iter = 0;
	while (iter < render.max_iter)
	{
		if ((z.real * z.real + z.imaginary * z.imaginary) > BREAK_POINT)
			break ;
		temp = z.real * z.real - z.imaginary * z.imaginary;
		z.imaginary = 2 * z.real * z.imaginary + render.c_imag;
		z.real = temp + render.c_real;
		iter++;
	}
	return (iter);
}
