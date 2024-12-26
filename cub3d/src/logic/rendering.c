/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:31:05 by melfersi          #+#    #+#             */
/*   Updated: 2024/09/30 13:01:54 by melfersi         ###   ########.fr       */
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
				+ (info->map.grid[i][j] == '0') * DARK_BROWN;
			rect(&info->map.data, (t_rect){
				j * T_SIZE * MINIMAP_SCALE_FAC,
				i * T_SIZE * MINIMAP_SCALE_FAC,
				T_SIZE * MINIMAP_SCALE_FAC,
				T_SIZE * MINIMAP_SCALE_FAC, color});
		}
	}
	update_player_pos_in_full_map(info);
}

int	rendering(t_info *info)
{
	init_img_data(info);
	update_player_position(info);
	raycasting(info);
	update_3d(info);
	mlx_put_image_to_window(info->mlx, info->win, info->map.data.img, 0, 0);
	return (0);
}

// full_map(info);
// render_rays(info);
// update_minimap(info);
// update_minimap_player(info);