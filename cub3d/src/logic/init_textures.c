/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:09:01 by melfersi          #+#    #+#             */
/*   Updated: 2024/09/30 12:59:01 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texture(t_info *info, t_condition *condition)
{
	int		i;

	info->tex.img[NORTH_ID].path = condition->pure_texture[0];
	info->tex.img[SOUTH_ID].path = condition->pure_texture[1];
	info->tex.img[WEST_ID].path = condition->pure_texture[2];
	info->tex.img[EAST_ID].path = condition->pure_texture[3];
	i = -1;
	while (++i < 4)
	{
		info->tex.img[i].data.img = mlx_xpm_file_to_image(info->mlx,
				info->tex.img[i].path,
				&info->tex.img[i].width,
				&info->tex.img[i].height);
		info->tex.img[i].data.addr = mlx_get_data_addr(
				info->tex.img[i].data.img,
				&info->tex.img[i].data.bits_per_pixel,
				&info->tex.img[i].data.line_length,
				&info->tex.img[i].data.endian);
	}
	info->tex.floor_pcolor = condition->floor_color;
	info->tex.ceiling_pcolor = condition->ceiling_color;
}
