/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 04:18:11 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/01/24 08:55:15 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

void	fractalsetup(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	fractal->img = mlx_new_image(fractal->mlx, fractal->width, fractal->height);
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel,&fractal->line_length, &fractal->endian);
	if (!ft_strncmp(fractal->name, "julia", 5))
		juliaset(fractal);
	else if (!ft_strncmp(fractal->name, "mandelbrot", 10))
		mandelbrotset(fractal);
	else if (!ft_strncmp(fractal->name, "burning", 7))
		burningset(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}

void	wronginputs(void)
{
	printf("svp entre une type : mandelbrot ou julia ou burning \n");
}

int	freeall(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	//mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_fractal		*fractal = malloc(sizeof(t_fractal));
	//fractal = malloc(sizeof(t_fractal));
	if (argc == 2)
	{
		if (!ft_strncmp(argv[1], "mandelbrot", 10) && ft_strlen(argv[1]) == 10)
			fractal = mandelbrot_param(fractal, argv[1]);
		else if (!ft_strncmp(argv[1], "julia", 5) && ft_strlen(argv[1]) == 5)
			fractal = julia_param(fractal, argv[1]);
		else if (!ft_strncmp(argv[1], "burning", 7) && ft_strlen(argv[1]) == 7)
			fractal = burning_param(fractal, argv[1]);
		fractal->mlx = mlx_init();
		fractal->win = mlx_new_window(fractal->mlx, fractal->width, fractal->height, fractal->name);
		fractal->img = mlx_new_image(fractal->mlx, fractal->width, fractal->height);
		fractalsetup(fractal);
		mlx_key_hook(fractal->win, key_hook, fractal);
		mlx_mouse_hook(fractal->win, mouse_hook, fractal);
		mlx_hook(fractal->win, 17, 1L << 17, close_game, fractal);
		mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
		mlx_loop(fractal->mlx);
	}
	else
		wronginputs();
	return (0);
}
