/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkornato <wkornato@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:04:33 by wkornato          #+#    #+#             */
/*   Updated: 2024/10/11 23:58:02 by wkornato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define NOT_SET -42

# define WIN_WIDTH 1000
# define WIN_HEIGHT 600

# define DIR_RIGHT 63
# define DIR_LEFT -63
# define DIR_UP -84
# define DIR_DOWN 84

# define MAX_ITER_COUNT 512
# define BREAK_POINT 4

# define MOUSE_CLICK 1
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef enum e_exit_status
{
	SUCCESS,
	FAILURE,
	MALLOC_ERROR,
	MLX_INIT_ERROR,
	MLX_WIN_ERROR,
	MLX_IMG_ERROR
}				t_exit_status;

typedef enum e_factals
{
	JULIA,
	MANDELBROT,
	BURNINGSHIP,
	HENON
}				t_fractal;

typedef struct s_image
{
	void		*image_pointer;
	char		*address;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

typedef struct s_render
{
	t_image		image;
	t_fractal	type;
	void		*window_pointer;
	void		*mlx_pointer;
	double		min_re;
	double		max_re;
	double		min_im;
	double		max_im;
	double		max_x;
	double		min_x;
	double		max_y;
	double		min_y;
	int			max_iter;
	double		c_real;
	double		c_imag;
}				t_render;

typedef struct s_complex
{
	double		real;
	double		imaginary;
}				t_complex;

void			close_window_and_exit(t_render *render, t_exit_status code);
void			print_argument_options_and_exit(void);
int				display_mandelbrot_set(t_render render, double x, double y);
int				display_julia_set(t_render render, double real, double imag);
void			my_mlx_pixel_put(t_image *data, int x, int y, int color);
int				on_keydown_handler(int key_code, t_render *render);
int				mouse_handler(int key_code, int x, int y, t_render *render);
int				red_cross_handler(t_render *render);
void			initialize_render_structure(t_render *render);
void			display_fractal(t_render render);
t_exit_status	for_each_pixel_run(t_render render,
					int (*draw_function)(t_render, double, double));
t_complex		complex_sum(t_complex a, t_complex b);
t_complex		complex_product(t_complex a, t_complex b);
int				complex_to_pow2(t_complex a);
int				get_color_from_iter(t_render render, int iter);
int				display_burningship_set(t_render render, double real,
					double imag);
void			clear_window(t_render render);
void			zoom_into_point(t_render *render, int x, int y);
void			move_image(t_render *render, double move_amount, int direction);
void			zoom_image(t_render *render, double zoom_amount);

#endif
