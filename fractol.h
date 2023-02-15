/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 04:17:47 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/01/24 08:57:57 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define ESC 53
# define LEFT 124
# define UP 126
# define RIGHT 123
# define DOWN 125
# define R 15
# define Z 122
# define PLUS 69
# define MINUS 78

typedef struct imaginary {
	double	x;
	double	y;
}			t_complex;

t_complex	sqr(t_complex a);
t_complex	add(t_complex a, t_complex b);

typedef struct s_fractal {
	char		*name;
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	t_complex	c;
	double		zoom;
	double		x;
	double		y;
	double		xarrow;
	double		yarrow;
	double		radius;
	int			iterations;
	int			color;
}				t_fractal;

t_complex	mappoint(t_fractal *julia, double x, double y);

void		juliaset(t_fractal *julia);
void		mandelbrotset(t_fractal *mandel);
void		burningset(t_fractal *burning);
int			my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color);
void		fractalsetup(t_fractal *fractal);
t_fractal	*mandelbrot_param(t_fractal *fractal, char *name);
t_fractal	*burning_param(t_fractal *fractal, char *name);
t_fractal	*julia_param(t_fractal *fractal, char *name);
void		ft_zoom(double x, double y, t_fractal *fractal);
void		ft_dezoom(double x, double y, t_fractal *fractal);
int			key_hook(int keycode, t_fractal *fractal);
int			mouse_hook(int key_code, int x, int y, t_fractal *fractal);
int			close_game(t_fractal *fractal);
int			freeall(t_fractal *fractal);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
#endif
