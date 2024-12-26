/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:10:46 by melfersi          #+#    #+#             */
/*   Updated: 2024/09/29 15:22:18 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	keypress_player(int keycode, t_info *info)
{
	if (keycode == W)
		info->player.walk_direction = 1;
	if (keycode == S)
		info->player.walk_direction = -1;
	if (keycode == LEFT)
		info->player.turn_direction = -1;
	if (keycode == RIGHT)
		info->player.turn_direction = 1;
	if (keycode == A)
		info->player.move_rightleft = -1;
	if (keycode == D)
		info->player.move_rightleft = 1;
	if (keycode == LEFT_SHIFT)
		info->player.move_speed = MOVE_SPEED * 2;
}

int	keypress(int keycode, t_info *info)
{
	keypress_player(keycode, info);
	if (keycode == ESC)
		ft_exit(info);
	if (keycode == E)
		door_key(info);
	if (keycode == NUM_1)
		info->active_weapon_id = 0;
	if (keycode == NUM_2)
		info->active_weapon_id = 1;
	if (keycode == NUM_3)
		info->active_weapon_id = 2;
	if (keycode == NUM_4)
		info->active_weapon_id = 3;
	if (keycode == G)
		info->weapon[info->active_weapon_id].is_guarding = true;
	if (keycode == Q)
		info->weapon[info->active_weapon_id].is_kneeling = true;
	return (0);
}

int	keyrelease(int keycode, t_info *info)
{
	if (keycode == W || keycode == S)
		info->player.walk_direction = 0;
	if (keycode == LEFT || keycode == RIGHT)
		info->player.turn_direction = 0;
	if (keycode == A || keycode == D)
		info->player.move_rightleft = 0;
	if (keycode == G)
		info->weapon[info->active_weapon_id].is_guarding = false;
	if (keycode == Q)
		info->weapon[info->active_weapon_id].is_kneeling = false;
	if (keycode == LEFT_SHIFT)
		info->player.move_speed = MOVE_SPEED;
	return (0);
}
