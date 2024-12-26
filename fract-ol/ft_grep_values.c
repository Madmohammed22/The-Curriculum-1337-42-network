/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grep_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 12:36:50 by mmad              #+#    #+#             */
/*   Updated: 2024/03/21 22:06:05 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bit_per_pixel / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

double	ft_coordinates(double num, double new_min, double new_max,
		double prev_max)
{
	return ((new_max - new_min) * (num) / (prev_max)
		+ new_min);
}

int	calculate_color_bonus(float iter, t_fractol *fractol)
{
	return (iter / fractol->range * PSYCHEDELIC_PURPLE);
}

void	ft_get_constant(t_data *z, t_data *constant, t_fractol *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", ft_strlen(fractal->name)))
	{
		constant->x = fractal->x_0;
		constant->y = fractal->y_0;
	}
	else
	{
		constant->x = z->x;
		constant->y = z->y;
	}
}
