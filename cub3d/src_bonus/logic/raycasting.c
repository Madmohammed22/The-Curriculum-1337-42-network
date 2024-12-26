/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:20:21 by melfersi          #+#    #+#             */
/*   Updated: 2024/09/29 11:24:05 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_rays(t_info *info)
{
	double	ray_angle;
	int		i;

	ray_angle = info->player.rotation_angle - deg_to_rad(FOV_ANGLE / 2);
	i = -1;
	while (++i < NUM_RAYS)
	{
		info->player.ray[i].ray_ang = normalize_angle(ray_angle);
		info->player.ray[i].is_ray_down = (info->player.ray[i].ray_ang > 0
				&& info->player.ray[i].ray_ang < M_PI);
		info->player.ray[i].is_ray_up = !info->player.ray[i].is_ray_down;
		info->player.ray[i].is_ray_right = (info->player.ray[i].ray_ang <= 0.5
				* M_PI || info->player.ray[i].ray_ang > 1.5 * M_PI);
		info->player.ray[i].is_ray_left = !info->player.ray[i].is_ray_right;
		ray_angle += deg_to_rad(FOV_ANGLE) / NUM_RAYS;
	}
}

t_type	hit(t_info *info, double x, double y)
{
	int		j;
	int		i;

	j = (int)(x / T_SIZE);
	i = (int)(y / T_SIZE);
	if (x < 0 || x >= info->width || y < 0 || y >= info->height)
		return (WALL);
	if (info->map.grid[i][j] == '1')
		return (WALL);
	if (info->map.grid[i][j] == 'B')
		return (C_DOOR);
	if (info->map.grid[i][j] == 'b')
		return (O_DOOR);
	return (EMPTY);
}

double	distence_ray(t_info *info, double x, double y)
{
	if (info->player.x == x && info->player.y == y)
		return (__DBL_MAX__);
	return (sqrt(pow(x - info->player.x, 2) + pow(y - info->player.y, 2)));
}

void	set_closest_ray(t_info *info, int i, t_intersec intersec)
{
	if (intersec.h_dis < intersec.v_dis)
	{
		info->player.ray[i].ray_dis = intersec.h_dis;
		info->player.ray[i].is_hor = true;
		info->player.ray[i].hit_x = intersec.h.x;
		info->player.ray[i].hit_y = intersec.h.y;
		info->player.ray[i].hit = intersec.h_hit;
	}
	else
	{
		info->player.ray[i].ray_dis = intersec.v_dis;
		info->player.ray[i].is_hor = false;
		info->player.ray[i].hit_x = intersec.v.x;
		info->player.ray[i].hit_y = intersec.v.y;
		info->player.ray[i].hit = intersec.v_hit;
	}
}

void	raycasting(t_info *info)
{
	int				i;
	t_intersec		intersec;
	double			correct_ray_dis;

	create_rays(info);
	i = -1;
	while (++i < NUM_RAYS)
	{
		set_horizonal_intersection(info, &intersec, i, WALL | C_DOOR);
		set_vertical_intersection(info, &intersec, i, WALL | C_DOOR);
		set_closest_ray(info, i, intersec);
		correct_ray_dis = info->player.ray[i].ray_dis
			* cos(info->player.ray[i].ray_ang - info->player.rotation_angle);
		info->player.ray[i].strip_height = (T_SIZE / correct_ray_dis)
			* info->player.plane_dis;
	}
}
