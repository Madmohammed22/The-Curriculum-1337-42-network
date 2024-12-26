/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:10:46 by melfersi          #+#    #+#             */
/*   Updated: 2024/09/29 11:15:14 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mousepress(int button, int x, int y, t_info *info)
{
	(void)x;
	(void)y;
	if (button == LEFT_CLICK)
		info->weapon[info->active_weapon_id].is_shooting = true;
	if (button == RIGHT_CLICK)
		info->weapon[info->active_weapon_id].is_aiming = true;
	if (button == SCROLL_UP)
	{
		info->active_weapon_id++;
		if (info->active_weapon_id == N_WEAPONS)
			info->active_weapon_id = 0;
	}
	if (button == SCROLL_DOWN)
	{
		info->active_weapon_id--;
		if (info->active_weapon_id == -1)
			info->active_weapon_id = N_WEAPONS - 1;
	}
	if (button == SCROLL_CLICK)
	{
		info->weapon[info->active_weapon_id].is_whiping = true;
	}
	return (0);
}

int	mouserelease(int button, int x, int y, t_info *info)
{
	(void)x;
	(void)y;
	if (button == LEFT_CLICK)
		info->weapon[info->active_weapon_id].is_shooting = false;
	if (button == RIGHT_CLICK)
		info->weapon[info->active_weapon_id].is_aiming = false;
	if (button == SCROLL_CLICK)
		info->weapon[info->active_weapon_id].is_whiping = false;
	return (0);
}

int	mousemove(int x, int y, t_info *info)
{
	(void)y;
	if (x > WIDTH / 2)
	{
		mlx_mouse_move(info->mlx, info->win, WIDTH / 2, HEIGHT / 2);
		info->player.rotation_angle += MOUSE_X_SENSITIVITY;
	}
	if (x < WIDTH / 2)
	{
		mlx_mouse_move(info->mlx, info->win, WIDTH / 2, HEIGHT / 2);
		info->player.rotation_angle -= MOUSE_X_SENSITIVITY;
	}
	return (0);
}
