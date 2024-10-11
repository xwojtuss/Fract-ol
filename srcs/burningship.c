/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkornato <wkornato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:45:56 by wkornato          #+#    #+#             */
/*   Updated: 2024/09/24 11:45:57 by wkornato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	display_burningship_set(t_render render, double real, double imag)
{
	int			iter;
	double		temp;
	t_complex	z;

	iter = 0;
	z = (t_complex){0, 0};
	while (z.real * z.real + z.imaginary * z.imaginary <= BREAK_POINT
		&& iter < render.max_iter)
	{
		temp = z.real * z.real - z.imaginary * z.imaginary + real;
		z.imaginary = fabs(2 * z.real * z.imaginary) + imag;
		z.real = temp;
		iter++;
	}
	return (iter);
}
