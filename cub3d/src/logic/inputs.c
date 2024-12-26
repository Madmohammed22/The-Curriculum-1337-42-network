/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:10:46 by melfersi          #+#    #+#             */
/*   Updated: 2024/09/30 12:56:44 by melfersi         ###   ########.fr       */
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
}

int	keypress(int keycode, t_info *info)
{
	keypress_player(keycode, info);
	if (keycode == ESC)
		ft_exit(info);
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
	return (0);
}
