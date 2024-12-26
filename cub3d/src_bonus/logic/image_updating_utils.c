/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_updating_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:33:11 by melfersi          #+#    #+#             */
/*   Updated: 2024/09/29 11:05:26 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_update_minimap_var(t_info *info, int *x, int *y, int *i)
{
	*x = (info->player.x > MM_RAD && !(info->player.x > info->width - MM_RAD))
		* (info->player.x - MM_RAD) + (info->player.x > info->width - MM_RAD)
		* (info->width - (MM_RAD * 2));
	*y = (info->player.y > MM_RAD && !(info->player.y > info->height - MM_RAD))
		* (info->player.y - MM_RAD) + (info->player.y > info->height - MM_RAD)
		* (info->height - (MM_RAD * 2));
	*i = (((info->player.y - MM_RAD) / T_SIZE - 1)
			* (info->player.y - MM_RAD > 0)) - 1;
}
