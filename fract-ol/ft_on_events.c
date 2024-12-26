/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_on_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:01:52 by mmad              #+#    #+#             */
/*   Updated: 2024/03/19 10:04:01 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_events(t_fractol *fractal)
{
	mlx_hook(fractal->window, KeyPress, KeyPressMask, ft_handle_key, fractal);
	mlx_hook(fractal->window, DestroyNotify, StructureNotifyMask, ft_close,
		fractal);
	mlx_hook(fractal->window, ButtonPress, ButtonPressMask, ft_handle_mouse,
		fractal);
}

void	ft_window_failed(void)
{
	perror("Failed:");
	exit(1);
}

void	ft_call_window(t_fractol *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (NULL == fractal->mlx_ptr)
		ft_window_failed();
	fractal->window = mlx_new_window(fractal->mlx_ptr, WIDTH, HEIGHT,
			fractal->name);
	if (NULL == fractal->window)
	{
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		ft_window_failed();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (NULL == fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_ptr, fractal->window);
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		ft_window_failed();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bit_per_pixel, &fractal->img.line_len,
			&fractal->img.endian);
	ft_events(fractal);
	ft_add_data(fractal);
}
