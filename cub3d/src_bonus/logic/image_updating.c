/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_updating.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:33:11 by melfersi          #+#    #+#             */
/*   Updated: 2024/09/29 11:05:05 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_update_minimap_var(t_info *info, int *x, int *y, int *i);

void	update_minimap(t_info *info)
{
	int	color;
	int	i;
	int	j;
	int	x;
	int	y;

	set_update_minimap_var(info, &x, &y, &i);
	while (++i < info->map.n_row)
	{
		j = (((info->player.x - MM_RAD) / T_SIZE - 1)
				* (info->player.x - MM_RAD > 0));
		while (j < info->map.n_cols)
		{
			color = (info->map.grid[i][j] == '1') * BROWN
				+ (info->map.grid[i][j] == '0') * WHITE
				+ (info->map.grid[i][j] == 'B') * RED
				+ (info->map.grid[i][j] == 'b') * GREEN;
			rect_cir(&info->map.data, (t_rect_cir){
				MINIMAP_SCALE_FAC * (j++) * T_SIZE - MINIMAP_SCALE_FAC * x,
				MINIMAP_SCALE_FAC * i * T_SIZE - MINIMAP_SCALE_FAC * y,
				MINIMAP_SCALE_FAC * T_SIZE, MINIMAP_SCALE_FAC * T_SIZE,
				MINIMAP_SCALE_FAC * MM_RAD, MINIMAP_SCALE_FAC * MM_RAD,
				MINIMAP_SCALE_FAC * MM_RAD, color});
		}
	}
}

bool	check_intersec_wall(t_info *info, double i, double j)
{
	int	x_inc;
	int	y_inc;

	x_inc = (int)i / T_SIZE - (int)info->player.x / T_SIZE;
	y_inc = (int)j / T_SIZE - (int)info->player.y / T_SIZE;
	if (1 == abs(x_inc) && 1 == abs(y_inc))
	{
		if (hit(info, info->player.x + x_inc * T_SIZE, info->player.y)
			&& hit(info, info->player.x, info->player.y + y_inc * T_SIZE))
			return (true);
	}
	return (false);
}

void	wall_collision(t_info *info, double new_x, double new_y)
{
	if (!hit(info, new_x, info->player.y))
		info->player.x = new_x;
	if (!hit(info, info->player.x, new_y))
		info->player.y = new_y;
}

void	update_player_position(t_info *info)
{
	double	new_x;
	double	new_y;

	info->player.rotation_angle += info->player.rotation_speed
		* info->player.turn_direction;
	info->player.rotation_angle = normalize_angle(info->player.rotation_angle);
	new_x = info->player.x + (cos(info->player.rotation_angle)
			* info->player.move_speed * info->player.walk_direction)
		+ (cos(info->player.rotation_angle + M_PI_2) * info->player.move_speed
			* info->player.move_rightleft);
	new_y = info->player.y + (sin(info->player.rotation_angle)
			* info->player.move_speed * info->player.walk_direction)
		+ (sin(info->player.rotation_angle + M_PI_2) * info->player.move_speed
			* info->player.move_rightleft);
	if ((!hit(info, new_x, new_y) || hit(info, new_x, new_y) == O_DOOR)
		&& !check_intersec_wall(info, new_x, new_y))
	{
		info->player.x = new_x;
		info->player.y = new_y;
	}
	else
		wall_collision(info, new_x, new_y);
}

// void	render_rays(t_info *info)
// {
// 	int	i;

// 	i = 0;
// 	while (i < NUM_RAYS)
// 	{
// 		draw_line(&info->map.data, (t_line){
// 			MINIMAP_SCALE_FAC * info->player.x,
// 			MINIMAP_SCALE_FAC * info->player.y,
// 			MINIMAP_SCALE_FAC * info->player.ray[i].hit_x,
// 			MINIMAP_SCALE_FAC * info->player.ray[i].hit_y,
// 			CYAN, 0, 0, 0});
// 		i++;
// 	}
// 	// i = MID_ANG_ID;
// 	// draw_line(&info->map.data, (t_line){
// 	// 	MINIMAP_SCALE_FAC * info->player.x, MINIMAP_SCALE_FAC * info->player.y,
// 	// 	MINIMAP_SCALE_FAC * info->player.ray[i].hit_x,
// 	// 	MINIMAP_SCALE_FAC * info->player.ray[i].hit_y,
// 	// 	CYAN, 0, 0, 0});
// }

void	update_minimap_player(t_info *info)
{
	int	x2;
	int	y2;
	int	player_x;
	int	player_y;

	if (info->player.x < MM_RAD)
		player_x = info->player.x;
	else
		player_x = MM_RAD;
	if (info->player.x > info->width - MM_RAD)
		player_x = MM_RAD + (info->player.x - (info->width - MM_RAD));
	if (info->player.y < MM_RAD)
		player_y = info->player.y;
	else
		player_y = MM_RAD;
	if (info->player.y > info->height - MM_RAD)
		player_y = MM_RAD + (info->player.y - (info->height - MM_RAD));
	draw_cir(&info->map.data, (t_cir){
		MINIMAP_SCALE_FAC * player_x, MINIMAP_SCALE_FAC * player_y,
		MINIMAP_SCALE_FAC * info->player.radius, RED});
	x2 = cos(info->player.rotation_angle) * 40 + player_x;
	y2 = sin(info->player.rotation_angle) * 40 + player_y;
	draw_line(&info->map.data, (t_line){
		player_x * MINIMAP_SCALE_FAC, player_y * MINIMAP_SCALE_FAC,
		x2 * MINIMAP_SCALE_FAC, y2 * MINIMAP_SCALE_FAC, BROWN, 0, 0, 0});
}
