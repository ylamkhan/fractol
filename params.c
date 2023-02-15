/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 04:19:15 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/01/24 11:18:54 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "fractol.h"

t_fractal	*mandelbrot_param(t_fractal *fractal, char *name)
{
	fractal->width = 500;
	fractal->height = 500;
	fractal->iterations = 60;
	fractal->zoom = 1;
	fractal->x = 0;
	fractal->y = 0;
	fractal->xarrow = 0;
	fractal->yarrow = 270;
	fractal->color = 0x0000FF00;
	fractal->name = name;
	return(fractal);
}

t_fractal	*julia_param(t_fractal *fractal, char *name)
{
	fractal->width = 500;
	fractal->height = 720;
	fractal->c.x = -0.7;
	fractal->c.y = 0.27015;
	fractal->radius = 3;
	fractal->iterations = 60;
	fractal->zoom = 1;
	fractal->x = 0;
	fractal->y = 0;
	fractal->xarrow = 0;
	fractal->yarrow = 0;
	fractal->color = 0xccf1ff;
	fractal->name = name;
	return (fractal);
}

t_fractal	*burning_param(t_fractal *fractal, char *name)
{
	fractal->width = 1280;
	fractal->height = 720;
	fractal->iterations = 150;
	fractal->zoom = 8.157307;
	fractal->x = 0;
	fractal->y = 0;
	fractal->xarrow = 1710.0;
	fractal->yarrow = 4530.0;
	fractal->color = 0xccf1ff;
	fractal->name = name;
	return (fractal);
}
