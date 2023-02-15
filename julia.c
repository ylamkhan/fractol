/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 04:18:46 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/01/24 11:28:36 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "fractol.h"

int	my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color)
{
	char	*dst;

	dst = fractal->addr + (y * fractal->line_length + x * (fractal->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return (0);
}

void	juliaset(t_fractal *julia)
{
	int			i;
	t_complex	z0;
	t_complex	z1;

	julia->x = -1;
	while (++julia->x <= julia->width)
	{
		julia->y = -1;
		while (++julia->y <= julia->height)
		{
			z0 = mappoint(julia, julia->x, julia->y);
			i = -1;
			while (++i <= julia->iterations)
			{
				z1 = add(sqr(z0), julia->c);
				printf("%f%f",z0.x,z0.y);
				exit(0);
				if (z1.x * z1.x + z1.y * z1.y > julia->radius * julia->radius)
				{
					my_mlx_pixel_put(julia, julia->x,julia->y, julia->color * i);
					break ;
				}
				z0 = z1;
			}
		}
	}
}
