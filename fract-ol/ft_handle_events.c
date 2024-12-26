/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:30:55 by mmad              #+#    #+#             */
/*   Updated: 2024/03/19 10:03:36 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_add_data(t_fractol *fractal)
{
	fractal->max_iterations = 100;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	fractal->range = 100;
}

int	ft_close(t_fractol *fractal)
{
	mlx_destroy_image(fractal->mlx_ptr, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_ptr, fractal->window);
	mlx_destroy_display(fractal->mlx_ptr);
	free(fractal->mlx_ptr);
	exit(0);
}

int	ft_handle_key(int key, t_fractol *fractal)
{
	if (key == Escape)
		ft_close(fractal);
	if (key == Left)
		fractal->shift_x += 0.5 * fractal->zoom;
	else if (key == Right)
		fractal->shift_x -= 0.5 * fractal->zoom;
	else if (key == Up)
		fractal->shift_y -= 0.5 * fractal->zoom;
	else if (key == Down)
		fractal->shift_y += 0.5 * fractal->zoom;
	else if (key == Plus)
		fractal->max_iterations += 10;
	else if (key == Minus)
		fractal->max_iterations -= 10;
	else if (key == XK_a)
		fractal->range -= 10;
	else if (key == XK_d)
		fractal->range += 10;
	fractal_render(fractal);
	return (0);
}

int	ft_handle_mouse(int button, int x, int y, t_fractol *fractal)
{
	(void)x;
	(void)y;
	if (button == Button4)
		fractal->zoom *= 0.80;
	else if (button == Button5)
		fractal->zoom *= 1.05;
	fractal_render(fractal);
	return (0);
}

int	ft_handle_mouse_track(int button, int x, int y, t_fractol *fractal)
{
	double	zoom_factor;
	double	mouse_x;
	double	mouse_y;

	if (button == Button4 || button == Button5)
	{
		if (button == 4)
			zoom_factor = 0.9;
		else
			zoom_factor = 1.1;
		fractal->zoom *= zoom_factor;
		mouse_x = ft_coordinates(x, -2, 2, WIDTH) * fractal->zoom
			+ fractal->shift_x;
		mouse_y = ft_coordinates(y, 2, -2, HEIGHT) * fractal->zoom
			+ fractal->shift_y;
		fractal->shift_x = mouse_x - (mouse_x - fractal->shift_x) * zoom_factor;
		fractal->shift_y = mouse_y - (mouse_y - fractal->shift_y) * zoom_factor;
		fractal_render(fractal);
	}
	return (0);
}
