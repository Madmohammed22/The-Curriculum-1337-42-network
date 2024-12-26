/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_cast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:28:20 by melfersi          #+#    #+#             */
/*   Updated: 2024/09/29 11:30:08 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	update_intersec_ver(t_info *info, t_intersec *intersec,
							int id, int type_hit)
{
	static double	start = 0;
	double			next_x;
	double			next_y;

	next_x = intersec->v.x + (intersec->step.x * start);
	next_y = intersec->v.y + (intersec->step.y * start);
	intersec->v.x = next_x;
	intersec->v.y = next_y;
	intersec->v_hit = hit(info,
			intersec->v.x - info->player.ray[id].is_ray_left,
			intersec->v.y);
	if (intersec->v_hit & type_hit)
		return (start = 0, false);
	start = 1;
	return (true);
}

void	set_vertical_intersection(t_info *info, t_intersec *intersec,
								int id, int type_hit)
{
	intersec->v.x = floor(info->player.x / T_SIZE) * T_SIZE;
	if (info->player.ray[id].is_ray_right)
		intersec->v.x += T_SIZE;
	intersec->v.y = info->player.y + ((intersec->v.x - info->player.x)
			* tan(info->player.ray[id].ray_ang));
	intersec->step.x = T_SIZE;
	if (info->player.ray[id].is_ray_left)
		intersec->step.x *= -1;
	intersec->step.y = T_SIZE * tan(info->player.ray[id].ray_ang);
	if (info->player.ray[id].is_ray_up && intersec->step.y > 0)
		intersec->step.y *= -1;
	if (info->player.ray[id].is_ray_down && intersec->step.y < 0)
		intersec->step.y *= -1;
	while (update_intersec_ver(info, intersec, id, type_hit))
		;
	intersec->v_dis = distence_ray(info, intersec->v.x, intersec->v.y);
}
