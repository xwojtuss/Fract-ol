/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkornato <wkornato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:45:59 by wkornato          #+#    #+#             */
/*   Updated: 2024/09/24 11:46:00 by wkornato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	complex_sum(t_complex a, t_complex b)
{
	return ((t_complex){a.real + b.real, a.imaginary + b.imaginary});
}

t_complex	complex_product(t_complex a, t_complex b)
{
	return ((t_complex){a.real * b.real - a.imaginary * b.imaginary, a.real
		* b.imaginary + a.imaginary * b.real});
}

int	complex_to_pow2(t_complex a)
{
	return (a.real * a.real + (a.imaginary * a.imaginary) * -1);
}
