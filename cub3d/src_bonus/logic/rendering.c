/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:31:05 by melfersi          #+#    #+#             */
/*   Updated: 2024/09/30 15:04:58 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_player_pos_in_full_map(t_info *info)
{
	draw_cir(&info->map.data, (t_cir){
		MINIMAP_SCALE_FAC * info->player.x,
		MINIMAP_SCALE_FAC * info->player.y, info->player.radius, RED});
	draw_line(&info->map.data, (t_line){
		MINIMAP_SCALE_FAC * info->player.x,
		MINIMAP_SCALE_FAC * info->player.y,
		MINIMAP_SCALE_FAC * info->player.x + MINIMAP_SCALE_FAC * 50
		* cos(info->player.rotation_angle),
		MINIMAP_SCALE_FAC * info->player.y + MINIMAP_SCALE_FAC * 50
		* sin(info->player.rotation_angle), RED, 0, 0, 0});
}

void	full_map(t_info *info)
{
	int	i;
	int	j;
	int	color;

	i = -1;
	while (++i < info->map.n_row)
	{
		j = -1;
		while (++j < info->map.n_cols)
		{
			color = (info->map.grid[i][j] == '1') * BROWN
				+ (info->map.grid[i][j] == '0') * DARK_BROWN
				+ (info->map.grid[i][j] == 'B') * RED
				+ (info->map.grid[i][j] == 'b') * GREEN;
			rect(&info->map.data, (t_rect){
				j * T_SIZE * MINIMAP_SCALE_FAC,
				i * T_SIZE * MINIMAP_SCALE_FAC,
				T_SIZE * MINIMAP_SCALE_FAC,
				T_SIZE * MINIMAP_SCALE_FAC, color});
		}
	}
	update_player_pos_in_full_map(info);
}

void	set_intersec(t_info *info, t_intersec *intersec)
{
	set_horizonal_intersection(info, intersec,
		(int)MID_ANG_ID, C_DOOR | O_DOOR | WALL);
	set_vertical_intersection(info, intersec,
		(int)MID_ANG_ID, C_DOOR | O_DOOR | WALL);
}

void	door_key(t_info *info)
{
	t_intersec	intersec;
	int			x;
	int			y;

	set_intersec(info, &intersec);
	if (intersec.h_dis < intersec.v_dis)
	{
		x = (int)intersec.h.x / T_SIZE;
		y = (int)(intersec.h.y - info->player.ray[(int)MID_ANG_ID].is_ray_up)
			/ T_SIZE;
		if (intersec.h_hit == C_DOOR && intersec.h_dis <= DOOR_RANGE_DIST)
			info->map.grid[y][x] = 'b';
		if (intersec.h_hit == O_DOOR && intersec.h_dis <= DOOR_RANGE_DIST)
			info->map.grid[y][x] = 'B';
	}
	else
	{
		x = (int)(intersec.v.x - info->player.ray[(int)MID_ANG_ID].is_ray_left)
			/ T_SIZE;
		y = (int)intersec.v.y / T_SIZE;
		if (intersec.v_hit == C_DOOR && intersec.v_dis <= DOOR_RANGE_DIST)
			info->map.grid[y][x] = 'b';
		if (intersec.v_hit == O_DOOR && intersec.v_dis <= DOOR_RANGE_DIST)
			info->map.grid[y][x] = 'B';
	}
}

int	rendering(t_info *info)
{
	init_img_data(info);
	update_player_position(info);
	raycasting(info);
	update_3d(info);
	first_person_view(info);
	update_minimap(info);
	update_minimap_player(info);
	mlx_put_image_to_window(info->mlx, info->win, info->map.data.img, 0, 0);
	return (0);
}
// full_map(info);
// render_rays(info);
