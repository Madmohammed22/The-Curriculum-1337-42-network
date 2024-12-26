/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:05:48 by melfersi          #+#    #+#             */
/*   Updated: 2024/09/29 15:59:42 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	deg_to_rad(double deg)
{
	return (deg * (M_PI / 180));
}

uint32_t	rgb_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

double	normalize_angle(double angle)
{
	angle = remainder(angle, (M_PI * 2));
	if (angle <= 0)
		angle += (M_PI * 2);
	return (angle);
}

t_argb	to_argb(uint32_t color)
{
	t_argb	argb;

	argb.a = (color >> 24) & 0xFF;
	argb.r = (color >> 16) & 0xFF;
	argb.g = (color >> 8) & 0xFF;
	argb.b = color & 0xFF;
	return (argb);
}

uint32_t	argb(uint32_t src_color, uint32_t bg_color, float alpha)
{
	t_argb	bg_argb;
	t_argb	src_argb;

	if (alpha > 1)
		alpha = 1;
	bg_argb = to_argb(bg_color);
	src_argb = to_argb(src_color);
	src_argb.a = (uint8_t)((alpha * src_argb.a) + ((1 - alpha) * bg_argb.a));
	src_argb.r = (uint8_t)((alpha * src_argb.r) + ((1 - alpha) * bg_argb.r));
	src_argb.g = (uint8_t)((alpha * src_argb.g) + ((1 - alpha) * bg_argb.g));
	src_argb.b = (uint8_t)((alpha * src_argb.b) + ((1 - alpha) * bg_argb.b));
	return ((src_argb.a << 24)
		| (src_argb.r << 16) | (src_argb.g << 8) | src_argb.b);
}
