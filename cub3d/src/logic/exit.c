/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:19:08 by melfersi          #+#    #+#             */
/*   Updated: 2024/10/01 12:19:01 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_exit(t_info *info)
{
	int		i;

	i = -1;
	mlx_destroy_window(info->mlx, info->win);
	mlx_destroy_image(info->mlx, info->map.data.img);
	while (++i < 4)
		mlx_destroy_image(info->mlx, info->tex.img[i].data.img);
	mlx_destroy_display(info->mlx);
	free(info->mlx);
	ft_hunt_leak();
	exit(0);
}
