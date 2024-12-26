/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_fractol_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:22:42 by mmad              #+#    #+#             */
/*   Updated: 2024/03/21 22:06:46 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_calculate(int x, int y, t_fractol *fractal)
{
	t_data	z;
	int		i;
	t_data	constant;

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
		return (BLACK);
	return (i);
}

int	ft_burningship(int x, int y, t_fractol *fractal)
{
	t_data	z;
	t_data	c;
	int		i;

	i = 0;
	z.x = (ft_coordinates(x, -2.0, +2.0, WIDTH) * fractal->zoom)
		+ fractal->shift_x;
	z.y = (ft_coordinates(y, +2.0, -2.0, HEIGHT) * fractal->zoom)
		+ fractal->shift_y;
	c.x = z.x;
	c.y = z.y;
	while ((z.x * z.x) + (z.y * z.y) < 4.0 && i < fractal->max_iterations)
	{
		z.temp = (z.x * z.x) - (z.y * z.y) + c.x;
		z.y = fabs(2 * z.x * z.y) + c.y;
		z.x = z.temp;
		i++;
	}
	if (i == fractal->max_iterations)
		return (WHITE);
	return (i);
}

void	ft_action(int x, int y, t_fractol *fractol, int (*f)(int x, int y,
			t_fractol *fractol))
{
	int	color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = calculate_color_bonus(f(x, y, fractol), fractol) * 2;
			ft_pixel_put(x, y, &fractol->img, color);
			x++;
		}
		y++;
	}
}

void	fractal_render(t_fractol *fractol)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	x = 0;
	color = 0;
	if (!ft_strncmp(fractol->name, "BurningShip", ft_strlen(fractol->name)))
		ft_action(x, y, fractol, ft_burningship);
	else
	{
		ft_action(x, y, fractol, ft_calculate);
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->window,
		fractol->img.img_ptr, 0, 0);
}
