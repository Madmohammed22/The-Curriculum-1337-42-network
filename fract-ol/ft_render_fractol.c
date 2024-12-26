/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_fractol.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 08:26:11 by mmad              #+#    #+#             */
/*   Updated: 2024/03/21 22:06:31 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_calculate(int x, int y, t_fractol *fractal)
{
	t_data	z;
	t_data	constant;
	int		i;

	i = 0;
	z.x = (ft_coordinates(x, -2.0, +2.0, WIDTH) * fractal->zoom)
		+ fractal->shift_x;
	z.y = (ft_coordinates(y, +2.0, -2.0, HEIGHT) * fractal->zoom)
		+ fractal->shift_y;
	ft_get_constant(&z, &constant, fractal);
	while ((z.x * z.x) + (z.y * z.y) < 4.0 && i < fractal->max_iterations)
	{
		z.temp = (z.x * z.x) - (z.y * z.y) + constant.x;
		z.y = (2 * z.x * z.y) + constant.y;
		z.x = z.temp;
		i++;
	}
	if (i == fractal->max_iterations)
		return (0);
	return (i);
}

int	calculate_color(float iter, t_fractol *fractol)
{
	(void)fractol;
	return (iter / 100 * 0x00ff00);
}

void	fractal_render(t_fractol *fractol)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = calculate_color(ft_calculate(x, y, fractol), fractol) * 2;
			ft_pixel_put(x, y, &fractol->img, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->window,
		fractol->img.img_ptr, 0, 0);
}
