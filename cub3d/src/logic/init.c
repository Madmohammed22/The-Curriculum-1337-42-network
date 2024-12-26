/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:05:42 by melfersi          #+#    #+#             */
/*   Updated: 2024/10/01 15:04:00 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_info *info, t_condition *condition)
{
	info->map.grid = condition->pure_map;
	info->map.n_row = condition->height_of_map;
	info->map.n_cols = condition->width_of_map;
	info->map.grid[condition->y_player][condition->x_player] = '0';
	info->width = info->map.n_cols * T_SIZE;
	info->height = info->map.n_row * T_SIZE;
	info->map.data.img = NULL;
}

void	init_player(t_info *info, t_condition *condition)
{
	info->player.x = (condition->x_player * T_SIZE) + (T_SIZE / 2);
	info->player.y = (condition->y_player * T_SIZE) + (T_SIZE / 2);
	info->player.radius = PLAYER_RADIUS;
	info->player.turn_direction = 0;
	info->player.walk_direction = 0;
	info->player.move_updown = 0;
	info->player.move_rightleft = 0;
	info->player.rotation_angle = condition->r_ang;
	info->player.move_speed = MOVE_SPEED;
	info->player.rotation_speed = ROTATION_SPEED * (M_PI / 180);
	info->player.plane_dis = (WIDTH / 2) / tan(deg_to_rad(FOV_ANGLE) / 2);
	info->player.ray = ft_malloc(sizeof(t_ray) * NUM_RAYS);
}

void	init_img_data(t_info *info)
{
	t_data	data;

	if (info->map.data.img)
	{
		mlx_destroy_image(info->mlx, info->map.data.img);
		info->map.data.img = NULL;
	}
	data.img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	info->map.data.addr = data.addr;
	info->map.data.img = data.img;
	info->map.data.bits_per_pixel = data.bits_per_pixel;
	info->map.data.line_length = data.line_length;
	info->map.data.endian = data.endian;
}
