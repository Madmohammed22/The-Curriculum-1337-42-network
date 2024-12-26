/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_cast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:31:22 by melfersi          #+#    #+#             */
/*   Updated: 2024/09/29 10:32:45 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	update_intersec_hor(t_info *info, t_intersec *intersec,
							int id, int type_hit)
{
	static double	start = 0;
	double			next_x;
	double			next_y;

	next_x = intersec->h.x + (intersec->step.x * start);
	next_y = intersec->h.y + (intersec->step.y * start);
	intersec->h.x = next_x;
	intersec->h.y = next_y;
	intersec->h_hit = hit(info, intersec->h.x, intersec->h.y
			- info->player.ray[id].is_ray_up);
	if (intersec->h_hit & type_hit)
		return (start = 0, false);
	start = 1;
	return (true);
}

void	set_horizonal_intersection(t_info *info, t_intersec *intersec,
									int id, int type_hit)
{
	intersec->h.y = floor(info->player.y / T_SIZE) * T_SIZE;
	if (info->player.ray[id].is_ray_down)
		intersec->h.y += T_SIZE;
	intersec->h.x = info->player.x + ((intersec->h.y - info->player.y)
			/ tan(info->player.ray[id].ray_ang));
	intersec->step.y = T_SIZE;
	if (info->player.ray[id].is_ray_up)
		intersec->step.y *= -1;
	intersec->step.x = T_SIZE / tan(info->player.ray[id].ray_ang);
	if (info->player.ray[id].is_ray_left && intersec->step.x > 0)
		intersec->step.x *= -1;
	if (info->player.ray[id].is_ray_right && intersec->step.x < 0)
		intersec->step.x *= -1;
	while (update_intersec_hor(info, intersec, id, type_hit))
		;
	intersec->h_dis = distence_ray(info, intersec->h.x, intersec->h.y);
}
