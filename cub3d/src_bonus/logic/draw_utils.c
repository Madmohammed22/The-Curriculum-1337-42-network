/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:08:20 by melfersi          #+#    #+#             */
/*   Updated: 2024/09/29 10:10:45 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// drawing a rectangle
void	rect(t_data *data, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < (rect.y + rect.height) && i < HEIGHT && i >= 0)
	{
		j = rect.x;
		while (j < (rect.x + rect.width) && j < WIDTH && j >= 0)
		{
			my_mlx_pixel_set(data, j, i, rect.color);
			j++;
		}
		i++;
	}
}

// drawing a rectangle with a circle inside
void	rect_cir(t_data *data, t_rect_cir rect_cir)
{
	int	i;
	int	j;

	i = rect_cir.y;
	while (i < (rect_cir.y + rect_cir.height) && i < rect_cir.radius * 2)
	{
		j = rect_cir.x;
		while (j < (rect_cir.x + rect_cir.width) && j < rect_cir.radius * 2)
		{
			if (sqrt(pow(j - rect_cir.cir_x, 2) + pow(i - rect_cir.cir_y, 2))
				<= rect_cir.radius)
				my_mlx_pixel_set(data, j, i, rect_cir.color);
			j++;
		}
		i++;
	}
}

// drawing a circle
void	draw_cir(t_data *data, t_cir cir)
{
	int	i;
	int	j;

	i = cir.y - cir.radius;
	while (i < cir.y + cir.radius)
	{
		j = cir.x - cir.radius;
		while (j < cir.x + cir.radius)
		{
			if (sqrt(pow(j - cir.x, 2) + pow(i - cir.y, 2))
				<= cir.radius)
				my_mlx_pixel_set(data, j, i, cir.color);
			j++;
		}
		i++;
	}
}

// drawing a line
// dx and dy are the difference between the two points
void	draw_line(t_data *data, t_line line)
{
	int	dx;
	int	dy;
	int	i;

	dx = line.x2 - line.x1;
	dy = line.y2 - line.y1;
	if (abs(dx) > abs(dy))
		line.step = abs(dx);
	else
		line.step = abs(dy);
	line.x_inc = dx / (float)line.step;
	line.y_inc = dy / (float)line.step;
	if (line.x2 < 0 || line.x2 > WIDTH || line.y2 < 0 || line.y2 > HEIGHT)
		return ;
	i = 0;
	while (i <= line.step)
	{
		my_mlx_pixel_set(data, line.x1, line.y1, line.color);
		line.x1 += line.x_inc;
		line.y1 += line.y_inc;
		i++;
	}
}

void	draw_img(t_data *data, t_img img, int x, int y)
{
	int	i;
	int	j;
	int	color;

	i = -1;
	while (++i < img.height)
	{
		j = -1;
		while (++j < img.width)
		{
			color = my_mlx_pixel_get(&img.data, j, i);
			if (!(color >> 24))
				my_mlx_pixel_set(data, x + j, y + i, color);
		}
	}
}
